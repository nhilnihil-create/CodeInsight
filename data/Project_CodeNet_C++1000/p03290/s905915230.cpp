#include<bits/stdc++.h>
using namespace std;
const bool DBG = 1;

#define TRACE(x)    x
#define WATCH(x)    TRACE(cout << #x" = " << x << endl)
#define WATCHR(a,b) TRACE(for(auto it=a; it!=b;) cout<<*(it++)<<" ";cout<<endl)
#define WATCHC(V)   TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})
#define all(x) (x).begin(), (x).end()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

void solve() {
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);

    ll D, G; cin >> D >> G;
    vi p(D), c(D);
    F0R(i,D) cin >> p[i] >> c[i];
    ll best_np = 1e6;
    F0R(fs,1<<D) {
        ll np = 0, ng = 0;
        F0R(i,D) {
            if(fs & (1<<i)) {
                np += p[i];
                ng += p[i]*100*(i+1) + c[i];
            }
        }
        int npcur = 0;
        F0Rd(i,D) {
            //cout << i << ": " << (!(fs & (1<<i))) << endl;
            if(!(fs & (1<<i))) {
                //if(G-ng > 100*p[i]*(i+1)) {
                //    np += p[i];
                //    ng += 100*p[i]*(i+1);
                //} else {
                    while(G-ng > 0 && npcur < p[i]) {
                        npcur++;
                        ng += 100*(i+1);
                    }
                //cout << "asdf: " << i << " " << np << " " << ng << endl;
                    break;
                //}
            }
        }
        np += npcur;
        //cout << fs << " " << np << " " << ng << endl;
        if(G>ng) continue;
        best_np = min(best_np, np);
    }
    cout << best_np << endl;

	return 0;
}
