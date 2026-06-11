#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > py(m);
    rep1(i, m){
        vector<ll> res(3);
        cin >> res[0] >> res[1];
        res[2] = i;
        py[i] = res;
    }
    sort(py.begin(), py.end());
    vector<P> ans(m);
    ll count = 1;
    rep1(i, m){
        if (i==0){
            ans[py[i][2]] = make_pair(py[i][0], count);
        }
        else if (py[i][0]==py[i-1][0]){
            count++;
            ans[py[i][2]] = make_pair(py[i][0], count);
        }
        else{
            count = 1;
            ans[py[i][2]] = make_pair(py[i][0], count);
        }
    }
    rep1(i, m){
        cout << setfill('0') << right << setw(6) << ans[i].first;
        cout << setfill('0') << right << setw(6) << ans[i].second << endl;
    }
    //printf("%.12f", ans);
}