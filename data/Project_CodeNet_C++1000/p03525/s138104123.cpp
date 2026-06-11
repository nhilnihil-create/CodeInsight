#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> c(13);
  int n;cin >> n;
  for(int i=0;i<n;i++){
    int d;cin >> d;
    c[d]++;
  }
  for(int i=0;i<13;i++){
    if(i==0){
      if(c[i]){
        cout << 0 << endl;
        return 0;
      }
    }
    else if(i==12){
      if(c[i]>=2){
        cout << 0 << endl;
        return 0;
      }
    }
    else{
      if(c[i]>=3){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<11);i++){
    vector<bool> d(25);
    for(int j=0;j<11;j++){
      if(c[j+1]==2){
        d[j+1]=true;
        d[23-j]=true;
      }
      else if(c[j+1]==1){
        if((i>>j)&1){
          d[j+1]=true;
        }
        else{
          d[23-j]=true;
        }
      }
    }
    d[0]=d[24]=true;
    d[12]=(c[12]>=1);
    int cnt=1,res=25;
    for(int i=1;i<25;i++){
      if(!d[i]){
        cnt++;
      }
      else{
        res=min(res,cnt);
        cnt=1;
      }
    }
    ans=max(ans,res);
  }
  cout << ans << endl;
}