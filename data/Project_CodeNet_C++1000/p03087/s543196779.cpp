#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

int main(){

  ll n,q;
  cin >> n>> q;
  string s;
  cin >> s;

  ll a[n]={};
  for(int i=0;i<n-1;i++){
    if(s[i]=='A' && s[i+1]=='C')a[i]=1;
  }

  ll b[n+1]={};

  for(int i=0;i<n;i++){
    b[i+1]=b[i]+a[i];
  }

  ll l,r;
  for(int i=0;i<q;i++){
    cin >> l >> r;
    ll m=b[r]-b[l-1];
    if(a[r-1]==1)m--;
    cout << max((ll)0,m) << endl;
  }
  
  


}