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
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ull INF = ULLONG_MAX;
const ll MOD = 998244353;


int main(){
  int N;ull X;cin>>N>>X;
  vector<ull> sumx(N+1,0);
  repeat(i,N){
    ll x;cin>>x;
    sumx[i+1]=sumx[i]+x;
  }
  //debugArray(sumx,N+1);
  ull ans = INF;
  for(int k=1;k<=N;k++){
    ull a=0;
    for(int j=1;(j-1)*k<N;j++){
      a += (sumx[N-(j-1)*k]-sumx[max(0,N-j*k)])*(j==1? 5:(2*j+1));
    }
    a += X*(N+k);
    ans = min(ans,a);
    //debug(ans);
  }
  cout << ans << endl;
  return 0;
}
