#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int MAX_N = 100005;
int N, L[MAX_N], R[MAX_N];

ll f(int p) {
    multiset<pii> LR, RL;
    rep(i, N) {
        LR.insert({ L[i],R[i] });
        RL.insert({ R[i],L[i] });
    }

    int x = 0;
    ll sm = 0;
    while (sz(LR)) {
        int l, r;
        if (p) {
            tie(l, r) = *LR.rbegin();
            if (l > x) {
                sm += l - x;
                x = l;
            } else {
                break;
            }
        } else {
            tie(r, l) = *RL.begin();
            if (r < x) {
                sm += x - r;
                x = r;
            } else {
                break;
            }
        }
        LR.erase(LR.find({ l,r }));
        RL.erase(RL.find({ r,l }));
        p = 1 - p;
    }

    sm += abs(x);
    RT sm;
}

void solve() {
    cin >> N;
    rep(i, N) {
        cin >> L[i] >> R[i];
    }

    ll re = max(f(0), f(1));
    cout << re << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}