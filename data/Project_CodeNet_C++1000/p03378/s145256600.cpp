#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  int n,m,x; cin>>n>>m>>x;
  int a,l=0,r=0;
  rep(i,m){
    cin>>a;
    if(a<x){l++;}
    else{r++;}
  }
  cout<<min(l,r);
}
      