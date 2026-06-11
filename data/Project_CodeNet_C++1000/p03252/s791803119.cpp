#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

const string YES = "Yes";
const string NO = "No";

void solve(std::string S, std::string T) {
    ll n = S.length();
    vector<ll> sv(26, -1), tv(26, -1);
    bool flg = true;
    rep(i, n) {
        ll sn = S[i] - 'a', tn = T[i] - 'a';
        if ((sv[sn] != -1 && sv[sn] != tn) || (tv[tn] != -1 && tv[tn] != sn)) flg = false;
        sv[sn] = tn;
        tv[tn] = sn;
        // cout << S[i] - 'a' << " " << v[S[i] - 'a'] << endl;
    }
    if (flg)
        cout << YES << endl;
    else
        cout << NO << endl;
}

int main() {
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(S, T);
    return 0;
}
