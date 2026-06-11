#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

struct val { int i; int v; };

int main() {
  int N; cin >> N;
  int l = pow(2,N);
  int A[l]; rep(i,l) cin >> A[i];
  vector<val> num[l];
  rep(i,l) {
    num[i].push_back({i,A[i]});
    num[i].push_back({l,0});
    rep(dig,N) {
      if (i&(1<<dig)) {
        int now = i^(1<<dig);
        num[i].push_back(num[now][0]);
        num[i].push_back(num[now][1]);
      }
    }
    sort(all(num[i]),[](const val &x, const val &y){return x.i<y.i;});
    sort(all(num[i]),[](const val &x, const val &y){return x.v>y.v;});
    num[i].erase(unique(all(num[i]),[](const val &x, const val &y){return x.i==y.i;}),num[i].end());
  }

  // rep(i,l) cout << num[i][0].v << " " << num[i][1].v << endl;
  int result[l] = {}; repr(i,1,l) result[i] = max(result[i-1],num[i][0].v+num[i][1].v);
  repr(i,1,l) cout << result[i] << endl;
  return 0;
}