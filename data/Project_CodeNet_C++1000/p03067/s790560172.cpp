#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef string str;
const long long INF = INT64_MAX;

#define REP(i, n) for(ll i=0;i<n;i++)
#define ASC(v) sort((v).begin(), (v).end())
#define DESC(v) sort((v).rbegin(), (v).rend())
#define UNIQ(v) ASC(v);erase(unique(v.begin(), v.end()), v.end())
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    if((a < c && c < b) || (b < c && c < a)) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}

int main() {
    FIO;
    solve();
    return 0;
}