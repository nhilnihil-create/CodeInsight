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
  int N;cin >> N;
  vll A(N),B(N);
  ll minB=INF;
  ll sum = 0;
  repeat(i,N){
    cin >> A[i] >> B[i];
    if(A[i]>B[i]){
      if(minB>B[i]){
        minB = B[i];
      }
    }
    sum += A[i];
  }
  ll ans = minB==INF? 0:sum - minB;
  cout << ans << endl;
  return 0;
}
