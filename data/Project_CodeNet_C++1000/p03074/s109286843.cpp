#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >>k;
  string s;
  cin >> s;

  vector<ll> v;

  if(s[0]=='0')v.push_back(0);

  ll b=s[0]-'0';
  for(int i=0;i<n;i++){
    ll a=0;
    while(s[i]-'0'==b){
      i++;
      a++;
    }
    i--;
    v.push_back(a);
    b=1-(s[i]-'0');
  }

  if(s[n-1]=='0')v.push_back(0);

  ll t=0;
  ll m=v.size();

  if(2*k>=m)cout << n << endl;
  else{
    ll S[m+1]={};
    for(int i=0;i<m;i++)S[i+1]=S[i]+v[i];
    for(int i=0;2*k+1+2*i<=m;i++){
      t=max(t,S[2*k+1+2*i]-S[2*i]);
    }
    cout << t << endl;
  }
  


  


}