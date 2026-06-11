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

int main(){
  int N;cin>>N;
  vector<pair<ll,int>> D(N);
  repeat(i,N){
    cin >> D[i].first;
    D[i].second = i+1;
  }
  sort(D.begin(),D.end());
  vll n(N,1);
  vector<vint> g(N);
  vector<Pii> edges;
  bool isok = true;
  for(int i=N-1;i>0;i--){
    debug(i);
    ll S = D[i].first+2*n[i]-N;
    int j = lower_bound(D.begin(),D.end(),pair<ll,int>(S,0))-D.begin();
    if(j>=i || D[j].first != S){
      isok = false;
      break;
    }
    edges.push_back({D[i].second,D[j].second});
    n[j]+=n[i];
    g[j].push_back(i);
  }
  queue<pair<ll,int>> Q;
  Q.push({0,0});
  ll S=0;
  while(!Q.empty()){
    Pii p = Q.front();
    Q.pop();
    S+=p.first;
    for(int u:g[p.second]){
      Q.push({p.first+1,u});
    }
  }
  isok &= S==D[0].first;
  if(!isok){
    cout <<-1<<endl;
    return 0;
  }
  repeat(i,edges.size()){
    cout << edges[i].first<<" "<<edges[i].second<<endl;
  }
  return 0;
}
