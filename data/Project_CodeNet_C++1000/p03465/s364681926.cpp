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

#define Nmax 2020200

int N, T, M, K, Q;



bitset<Nmax> B1,B2;

int A[2020];
ll sm = 0;

int main() {

  cin.sync_with_stdio(false);

  cin >> N;

  FOR(i, N) {

    cin >> A[i];
    sm += A[i];

  }
  double v = sm / 2.0;
  B1[0] = 1;
  FOR(i, N) {
    bitset<Nmax> B2;
    B1 = B1 | (B1 << A[i]);
  }
  int ret = 0;
  for(int i=0;i<=sm;++i) {
   //cout << B1[i] << endl;
    if(B1[i] && i >= v) {
      ret = i;
      break;
    }
  }
  cout << ret << endl;

  

}

 