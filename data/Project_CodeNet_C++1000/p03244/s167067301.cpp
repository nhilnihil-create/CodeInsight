#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    map<int, int> even, odd;
    rep(i, n) {
        int v; cin >> v;
        if(i % 2 == 0) even[v]++;
        else odd[v]++;
    }
    even[0]; odd[0];
    vector<P> vec_even, vec_odd;
    for(auto x : even) {
        vec_even.push_back(P(x.first, x.second));
    }
    for(auto x : odd) {
        vec_odd.push_back(P(x.first, x.second));
    }
    sort(ALL(vec_even), [](P a, P b) {
        return a.second > b.second;
    });
    sort(ALL(vec_odd), [](P a, P b) {
        return a.second > b.second;
    });
    int ans = n - vec_even[0].second - vec_odd[0].second;
    if(vec_even[0].first == vec_odd[0].first) {
        ans = min(n - vec_even[0].second - vec_odd[1].second, n - vec_even[1].second - vec_odd[0].second);
    }

    cout << ans << endl;

    return 0;
}