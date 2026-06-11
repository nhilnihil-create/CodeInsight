#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

const int MAX = 100010;
const int MOD = 1000000007;
const int INF = 1e8;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;

// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
//

int main() {
    int m, k;
    cin >> m >> k;

    int max = (1 << m) -1;
    if(k > max) {
        cout << -1 << endl;
    }
    else if(k == 0) {
        for(int i = 0; i <= max; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
    else {
        vi res, tmp;
        for(int i = 0; i <= max; i++) {
            if(i != k) {
                res.pb(i);
                tmp.pb(i);
            }
        }
        res.pb(k);
        int idx = res.size()-1;

        reverse(all(tmp));
        for(auto val : tmp)
        res.pb(val);
        res.pb(k);

        int x = 0;
        for(int i = idx; i < (int)res.size(); i++) {
            x = x ^ res[i];
        }

        if(x != k) {
            cout << -1 << endl;
        }
        else {
            for(auto r : res)
                cout << r << " ";
            cout << endl;
        }
    }

    return 0;
}
