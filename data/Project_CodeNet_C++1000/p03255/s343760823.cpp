#include <bits/stdc++.h>

using namespace std;
#define ll long long

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

#ifdef LOCAL
#define lcout(a) cout << a;
#define lcoutln(a) cout << a << endl;
#define lcerr(a) cerr << a;
#define lcerrln(a) cerr << a << endl;
#else
#define lcout(a) 
#define lcoutln(a) 
#define lcerr(a) 
#define lcerrln(a) 
#endif

#define MOD 1000000007

void init();
void solve();

signed main()
{
        init();
        solve();
}

ll N, X;
vector<ll> v;

void init()
{
        cin >> N >> X;
        v.resize(N+1);
        rrep(i, N) cin >> v[i+1];
        v[0] = 0;
        reps(i, 1, N+1) v[i] += v[i-1];
}

void solve()
{
        ll res = 8e18;
        rreps(i, N / 2 + 2, 1) {
                ll k = i * X + N * X;
                int st = 0;
                ll en = i;
                int x = 3;
                while (st < N) {
						if (res < k) break;
                        k += max(x, 5) * (v[en] - v[st]);
                        st = en;
                        en += i;
                        en = min(N, en);
                        x += 2;
                }
                res = min(res, k);
        }
        cout << res << endl;
}
