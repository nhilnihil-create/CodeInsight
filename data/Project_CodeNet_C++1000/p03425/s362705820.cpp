#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll cal(int k, vector<ll> var){
  ll ans=0;
  for(int p=0; p<k-2; p++){
    for(int q=p+1; q<k-1; q++){
      for(int r=q+1; r<k; r++){
        ans+=var[p]*var[q]*var[r];
      }
    }
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  map<char,ll> mp;
  rep(i,n){
    string s;
    cin>>s;
    if(s[0]=='M') mp['M']++; 
    if(s[0]=='A') mp['A']++;
    if(s[0]=='R') mp['R']++;
    if(s[0]=='C') mp['C']++;
    if(s[0]=='H') mp['H']++;
  }
  int kind=0;
  vector<ll> var;
  if(mp['M']!=0) {kind++; var.push_back(mp['M']);}
  if(mp['A']!=0) {kind++; var.push_back(mp['A']);}
  if(mp['R']!=0) {kind++; var.push_back(mp['R']);}
  if(mp['C']!=0) {kind++; var.push_back(mp['C']);}
  if(mp['H']!=0) {kind++; var.push_back(mp['H']);}
  ll ans=0;
  if(kind>=3){
    ans=cal(kind,var);
  }
  cout<<ans<<endl;
}

