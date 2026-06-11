#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<double, double>P;
typedef tuple<ll, int, int>T;
#define PI 3.14159265358979
int N, Q;
int const INF = 0;

struct SegmentTree {
private:    
    ll n;
    vector<ll> node;
public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1, INF);
        for (ll i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (ll i = n - 2; i >= 0; i--) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val) {
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    ll getmax(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];

        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};

int main() {
    ll N;
    cin>>N;
  	ll H[N],A[N];
  	rep(i,N){
    	cin>>H[i];
    }
  	rep(i,N){
    	cin>>A[i];
    }
  ll dp[N+1];
    SegmentTree seg(vector<ll>(1<<24, INF));
    for (int i = 0; i < N; i++) {
      ll gg=seg.getmax(0,H[i])+A[i];
      seg.update(H[i],gg);
    }
  cout<<seg.getmax(0,1<<23);
}