#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll mod=1e9+7;
  int n;
  string s;
  string a="abcdefghijklmnopqrstuvwxyz";
  cin>>n>>s;
  ll ans=1;
  ll vec[26]={};
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++){
      if(s[i]==a[j]){
        vec[j]++;
      }
    }
  }
  for(int i=0;i<26;i++){
    ans*=vec[i]+1;
    ans%=mod;
  }
  cout<<ans-1<<endl;
}