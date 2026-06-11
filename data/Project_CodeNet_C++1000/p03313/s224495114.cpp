#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);
 
#define MOD 1000000007
void init();
void solve();

signed main()
{
    init();
    solve();
}

int N, l;
vector<int> a;
vector<pair<int, int> > b;

void init()
{
    cin >> N;
    l = 1 << N;
    CINV(a, l);
    b.RS(l);
    rep(i, l) {
        b[i] = MP(a[i], 0);
    }
}

void mer(pair<int, int>& a, pair<int, int> b) {
    int a1 = a.first;
    int a2 = a.second;
    int b1 = b.first;
    int b2 = b.second;
    if (a1 <= b1) {
        a2 = a1;
        a1 = b1;
    } else if (a2 < b1) {
        a2 = b1;
    }
    if (a2 < b2) {
        a2 = b2;
    }
    a.first = a1;
    a.second = a2;
}


void solve()
{
    rep(i, N) {
        rep(j, l) {
            if ((j & (1 << i))) {
                mer(b[j], b[j ^ (1 << i)]);
            }
        }
    }
    int ma = 0;
    reps(i, 1, l) {
        ma = max(ma, b[i].first + b[i].second);
        cout << ma << endl;
    }
}

