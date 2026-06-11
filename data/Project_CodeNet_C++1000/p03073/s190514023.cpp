#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  ll n=s.size();

  ll e=0,o=0;
  
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      e+=s[2*i]-'0';
      o+=s[2*i+1]-'0';
    }
    cout << n/2-max(e,o)+min(e,o) << endl;
  }
  else{
    for(int i=0;i<n/2;i++){
      e+=s[2*i]-'0';
      o+=s[2*i+1]-'0';
    }
    e+=s[n-1]-'0';
    if(e>o)cout << n/2+1-e+o << endl;
    else cout << n/2-o+e << endl;
  }
  



}