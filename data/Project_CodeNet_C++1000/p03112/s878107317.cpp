#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

vector<ll> s;
vector<ll> t;
vector<ll> x;

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    ll tmp;

    s.push_back(-LINF);
    t.push_back(-LINF);

    rep(i, a) {
        cin >> tmp;
        s.push_back(tmp);
    }
    rep(i, b) {
        cin >> tmp;
        t.push_back(tmp);
    }
    rep(i, q) {
        cin >> tmp;
        x.push_back(tmp);
    }
    s.push_back(LINF);
    t.push_back(LINF);


    rep(i, q){
        auto itr_s = upper_bound(s.begin(), s.end(), x[i]);
        auto itr_t = upper_bound(t.begin(), t.end(), x[i]);
        int ind_s = itr_s - s.begin();
        int ind_t = itr_t - t.begin();
        ll tmp_1 = max(s[ind_s] - x[i], t[ind_t] - x[i]);
        ll tmp_2 = max(x[i] - s[ind_s - 1], x[i] - t[ind_t - 1]);
        ll tmp_3 = s[ind_s] - t[ind_t - 1] + min(s[ind_s] - x[i], x[i] - t[ind_t - 1]);
        ll tmp_4 = t[ind_t] - s[ind_s - 1] + min(t[ind_t] - x[i], x[i] - s[ind_s - 1]);
        // cout << tmp_1 << " " << tmp_2 << " " << tmp_3 << " " << tmp_4 << endl;
        cout << min({tmp_1, tmp_2, tmp_3, tmp_4}) << endl;
    }

    return 0;
}