#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n,a,b; cin>>n>>a>>b;
  int c[n]; for(int i=0;i<n;i++) c[i]=i+1;

  if (n<a||n<b) {
    cout<<-1<<endl;
    return 0;
  }

  int ii=0, p=n, q=1;
  reverse(c,c+b);
  ii = b; p -= b-1; q = b;

  while(ii < n && p > a) {
    if (p-a >= b-1) {
      if (ii+b > n) break;
      reverse(c+ii,c+ii+b);
      ii += b; p -= b-1;
    } else {
      if (ii+p-a+1 > n) break;
      reverse(c+ii,c+ii+p-a+1);
      ii += p-a; p -= p-a;
    }
  }
  if (p != a || q != b) {
    cout<<-1<<endl;
    return 0;
  } else {
    for(int i=0;i<n;i++) {
      cout<<c[i]<<" ";
    } cout<<endl;
  }
}
