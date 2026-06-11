#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> west(n+1),east(n+1);
  west[0]=0;
  east[0]=0;
  int ans=1000000;
  for(int i=0;i<n;++i){
    if(s[i]=='W'){
      west[i+1]=west[i]+1;
      east[i+1]=east[i];
    }else{
      east[i+1]=east[i]+1;
      west[i+1]=west[i];
    }
  }
  for(int i=0;i<n;++i){
    int cal=0;
    if(i==0){
      if(s[i]=='W'){
        cal=east[n];
      }else{
        cal=west[n];
      }
    }else if(i==n-1){
      if(s[i]=='W'){
        cal=east[n-1];
      }else{
        cal=west[n-1];
      }
    }else{
        cal=west[i];
        cal+=east[n]-east[i+1];
    }
    ans=min(cal,ans);
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
