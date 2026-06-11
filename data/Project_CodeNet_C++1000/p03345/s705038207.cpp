#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
const ll mod = 10e9+7;

int main(){
  int a,b,c;
  ll k;
  cin>>a>>b>>c>>k;
  if (k%2==0) cout << a-b;
  else cout << b-a;
}