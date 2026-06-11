#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

struct edge{
  int src,dst,weight;
};

int main(){
  int L;cin>>L;
  vector<edge> E;
  int N=20;
  for(;N>1&&(1<<(N-1))>L;N--);
  repeat(i,N-1){
    E.push_back({(int)(i+1),(int)(i+2),0});
    E.push_back({(int)(i+1),(int)(i+2),1<<i});
  }
  int n=N-1;
  L-=1<<n;
  int l = 0;
  while(L>0){
    l += 1<<n;
    for(;n>=0&&(1<<n)>L;n--);
    E.push_back({n+1,N,l});
    L -= 1<<n;
  }
  cout << N << " " << E.size()<<endl;
  repeat(i,E.size()){
    cout << E[i].src << " " << E[i].dst << " " << E[i].weight<<endl;
  }
  return 0;
}
