#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    vector<ll> B(m), C(m);
    rep(i, m) cin >> B[i] >> C[i];
    
    typedef pair<ll, ll> P;
    
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, n) que.push(P(A[i], 1));

    rep(i, m) {
        ll cnt = 0;
        ll b = B[i];
        while (true) {
            if (que.empty()) break;

            P q = que.top();
            if (q.first >= C[i]) {
                break;
            }
            else {
                que.pop();
                cnt += q.second;
                if (b < cnt) {
                    P q2 = P(q.first, cnt - b);
                    que.push(q2);
                    cnt = b;
                }
                if (b == cnt) {
                    break;
                };
            }
        }
        que.push(P(C[i], cnt));
    }

    ll res = 0;
    while (que.empty() == false) {
        res += que.top().first * que.top().second;
        que.pop();
    }
    put(res);
}
signed main(){ Main();return 0;}