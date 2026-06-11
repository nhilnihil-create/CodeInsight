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

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

int main() {
  int Q;cin >> Q;
  repeat(q,Q){
    ll A,B;cin >> A >> B;
    if(A>B) swap(A,B);
    ll root = sqrt(A*B);
    ll ans = root*(root+1)<A*B? 2*root-1:2*root-2;
    if(A!=B&&root*root==A*B) ans--;
    cout << ans << endl;
  }
  return 0;
}
