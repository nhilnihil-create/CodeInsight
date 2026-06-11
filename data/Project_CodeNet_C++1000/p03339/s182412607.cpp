#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int n;
  cin>>n;
  string s;
  cin >> s;
  int sum[n]={};
  for(int i=1;i<n;i++){
    if(s[i]=='E')sum[0]++;
  }
  for(int i=1;i<n;i++){
    sum[i]=sum[i-1];
    if(s[i-1]=='W'){sum[i]++;}
    if(s[i]=='E'){sum[i]--;}
  }

  int ans=n;
  rep(i,n){
    ans=min(ans,sum[i]);
  }

  cout << ans << endl;
}