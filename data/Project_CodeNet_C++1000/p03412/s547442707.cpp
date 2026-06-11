#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
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
const ll INF = INT_MAX;


int main() {
  int N;cin >> N;
  vint a(N),b(N);
  repeat(i,N){
    cin >> a[i];
  }
  repeat(i,N){
    cin >> b[i];
  }
  int ans=0;
  repeat(k,29){
    int T = 1<<k;
    vint amod(N),bmod(N);
    repeat(i,N){
      amod[i] = a[i]%(2*T);
      bmod[i] = b[i]%(2*T);
    }
    sort(bmod.begin(),bmod.end());
    int numbit=0;
    repeat(i,N){
      numbit += (lower_bound(bmod.begin(),bmod.end(),2*T-amod[i])
                      -lower_bound(bmod.begin(),bmod.end(),T-amod[i]));
      numbit += (lower_bound(bmod.begin(),bmod.end(),4*T-amod[i])
                      -lower_bound(bmod.begin(),bmod.end(),3*T-amod[i]));
    }
    //debug(numbit);
    if(numbit&1){
      ans += 1<<k;
    }
  }
  cout << ans << endl;
  return 0;
}
