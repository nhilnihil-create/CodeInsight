#include <bits/stdc++.h>
using namespace std;

int ans=0;
void dfs(vector<int> &cnt,vector<bool> &hour,int now){
  if(now==13){
    int mi=24;
    for(int i=0;i<24;i++){
      if(!hour.at(i)) continue;
      for(int j=i+1;j<24;j++){
        if(!hour.at(j)) continue;
        mi=min({mi,j-i,24-(j-i)});
      }
    }
    ans=max(ans,mi);
    return;
  }

  if(cnt.at(now)==0){
    dfs(cnt,hour,now+1);
  }
  else if(cnt.at(now)==1){
    hour.at(now)=true;
    dfs(cnt,hour,now+1);
    hour.at(now)=false;
    hour.at(24-now)=true;
    dfs(cnt,hour,now+1);
    hour.at(24-now)=false;
  }
}

int main(){
  int N;
  cin >> N;
  vector<int> cnt(13,0);
  cnt.at(0)=1;
  for(int i=0;i<N;i++){
    int d;
    cin >> d;
    cnt.at(d)++;
  }

  if(cnt.at(0)>=2 || cnt.at(12)>=2){
    cout << 0 << endl;
    return 0;
  }
  for(int i=1;i<12;i++){
    if(cnt.at(i)>=3){
      cout << 0 << endl;
      return 0;
    }
  }

  vector<bool> hour(24,false);
  hour.at(0)=true;
  cnt.at(0)=0;
  for(int i=0;i<13;i++){
    if(cnt.at(i)==2){
      hour.at(i)=true;
      hour.at(24-i)=true;
      cnt.at(i)=0;
    }
  }
  dfs(cnt,hour,0);
  cout << ans << endl;

  return 0;
}