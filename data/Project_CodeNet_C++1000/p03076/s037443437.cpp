#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int>ti(5);
  for(int i=0;i<5;i++)
    cin >> ti.at(i);
  for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
      if((ti.at(j)%10!=0&&ti.at(j)%10<ti.at(j+1)%10)||ti.at(j+1)%10==0)
        swap(ti.at(j),ti.at(j+1));
    }
  }
  int ans=0;
  for(int i=0;i<5;i++){
    //cout << ti.at(i) << "#";
    if(ans%10!=0)
      ans=(ans/10+1)*10;
    ans+=ti.at(i);
  }
  cout << ans << endl;
  return 0;
}