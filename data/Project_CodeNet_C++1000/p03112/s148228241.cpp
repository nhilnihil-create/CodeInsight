#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

int main(){
    int A, B, Q; cin >> A >> B >> Q;

    vector<ll> s(A), t(B), x(Q);
    rep(i,A) cin >> s[i];
    rep(i,B) cin >> t[i];
    s.push_back(INF); s.push_back(-INF);
    t.push_back(INF); t.push_back(-INF);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    rep(i,Q) cin >> x[i];

    rep(i,Q){

        int s_left = upper_bound(s.begin(), s.end(), x[i]) - s.begin()-1;
        int s_right = lower_bound(s.begin(), s.end(), x[i]) - s.begin();
        int t_left = upper_bound(t.begin(), t.end(), x[i]) - t.begin()-1;
        int t_right = lower_bound(t.begin(), t.end(), x[i]) - t.begin();

        ll s_distances[2];
        s_distances[0] = s[s_left];
        s_distances[1] = s[s_right];

        ll t_distances[2];
        t_distances[0] = t[t_left];
        t_distances[1] = t[t_right];

        ll ans = INF;
        for (int j = 0; j < 2; j++){
            ans = min(ans, abs(x[i] - s_distances[j]) +abs(s_distances[j] - t_distances[j]));
            ans = min(ans, abs(x[i] - s_distances[j]) +abs(s_distances[j] - t_distances[(j+1)%2]));
        }
        for (int j = 0; j < 2; j++){
            ans = min(ans, abs(x[i] - t_distances[j]) +abs(t_distances[j] - s_distances[j]));
            ans = min(ans, abs(x[i] - t_distances[j]) +abs(t_distances[j] - s_distances[(j+1)%2]));
        }

        printf("%lld\n", ans);

    }


}