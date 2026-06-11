#include <bits/stdc++.h>

 

#define pb push_back

#define mp make_pair

#define fs first

#define sc second

#define rep(i, from, to) for (int i = from; i < (to); ++i)

#define all(x) x.begin(), x.end()

#define sz(x) (int) (x).size()

#define FOR(i, to) for (int i = 0; i < (to); ++i)

 

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef pair<int,int> pii;

typedef pair<double,double> pdd;

typedef vector<ll> vll;

typedef vector<pair<int,int>> vpi;

typedef pair<ll,ll> pll;

typedef vector<string> vs;

#define MOD 998244353

#define mod 998244353

#define INF 1000000000LL * 100000000LL

#define Nmax 202020

int N, T, M, K, Q;



ll A[202020];


int main() {

  cin.sync_with_stdio(false);

  cin >> N;
  FOR(i, N) {
    cin >> A[i];
  }
  if(A[N-1] != 2) {
    cout << "-1"; return 0;
  } else {
    ll mn = 2;
    ll ma = 3;
    for(int i=N-2;i>=0;--i) {
      if(mn % A[i] != 0)
      mn = mn + (A[i] - (mn % A[i]));
      ma = ma - (ma % A[i]) + A[i] - 1;
      
      if(mn > ma) {
        cout << "-1";
        return 0;
      }
      
    }
    cout << mn << " " << ma << endl;
  }

}

 