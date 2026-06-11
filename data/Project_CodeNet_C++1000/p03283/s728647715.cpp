#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    VP train(m);
    rep(i,m){
        int L, R;
        cin >> L >> R;
        L--; R--;
        train[i].first = L;
        train[i].second = R;
    }
    sort(all(train));

    VVI town(n);
    rep(i,m){
        int L, R;
        L = train[i].first;
        R = train[i].second;
        town[L].push_back(R);
    }

    rep(i,q){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = 0;
        for(int t = l; t <= r; t++){
            auto itr = upper_bound(all(town[t]), r);
            if (itr == town[t].begin()) continue;
            ans += itr - town[t].begin();
        }
        cout << ans << endl;
    }
    return 0;
}