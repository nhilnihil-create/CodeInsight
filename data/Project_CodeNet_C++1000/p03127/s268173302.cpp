#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int GCD(int a, int b){
  if(a<b){swap(a,b);}  
  if(a%b==0){return b;}
  else{return GCD(a%b,b);}
}

int main() {
  int n; cin>>n;
  vector<int> v(n);
  rep(i,n){cin>>v[i];}
  int g= GCD(v[0],v[1]);
  rep(i,n){
    g=GCD(g,v[i]);
    if(g==1)break;
  }
  cout<<g;
}