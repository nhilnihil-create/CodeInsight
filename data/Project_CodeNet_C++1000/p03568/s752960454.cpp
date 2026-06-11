#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main(){
  int n; cin>>n;
  ll an=1; for(int i=0;i<n;i++) an*=3;
  ll h=1;
  for(int i=0;i<n;i++) {
    int a; cin>>a;
    if (a%2==0) h*=2;
  }
  an-=h;
  cout<<an<<endl;
}