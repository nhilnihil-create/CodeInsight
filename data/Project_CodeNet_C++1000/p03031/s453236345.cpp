#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int cal(vector<int> onoff,int now,int num,int bulb,vector<vector<int>> swit,vector<int> extra){
  if(now < num){
    int p = cal(onoff,now+1,num,bulb,swit,extra);
    onoff[now] = 1;
    return p+cal(onoff,now+1,num,bulb,swit,extra);
  }
  for(int i = 0;i < bulb;i ++){
    int p = 0;
    int z = swit[i].size();
    for(int j = 0;j < z;j ++){
      if(onoff[swit[i][j]] == 1){
        p++;
      }
    }
    if(p % 2 != extra[i]){
      return 0;
    }
    
  }
  return 1;
  
}


int main(void){
  int num,bulb;
  vector<vector<int>> swit;
  cin >> num >> bulb;
  for(int i = 0;i < bulb;i ++){
    int p,q;
    cin >> p;
    swit.insert(swit.end(),vector<int>(p));
    for(int j = 0;j < p;j ++){
      cin >> q;
      swit[i][j] = q-1;
    }
  }
  vector<int> extra(bulb);
  for(int i = 0;i < bulb;i ++){
    cin >> extra[i];
  }
  vector<int> onoff(num,0);
  int ans = cal(onoff,0,num,bulb,swit,extra);
  cout << ans << endl;

  return 0;
}