#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  ll n,m;cin>>n>>m;
  if(n==1&&m==1){cout<<1;}
  else if(n==1){cout<<m-2;}
  else if(m==1){cout<<n-2;}
  else{cout<<(n-2)*(m-2);}
}