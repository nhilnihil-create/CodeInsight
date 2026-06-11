#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const int int_inf = 100000000;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, tmp;
    cin >> n;

    vector<int> b(n), ans;
    vector<bool> x(n, true);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int now = 0, idx = -1;

        for (int j = 0; j < n; j++) {
            if (x[j]) now++;
            if (b[j] == now) idx = j;
            //cout << b[j] << " " << now << endl;
        }
        //cout << "----------" << endl;
        //cout << i << " " << now << " " << idx << endl;
        if (idx == -1) {
            cout << -1 << endl;
            return 0;
        }
        //cout << idx+1 << endl;
        ans.push_back(b[idx]);
        x[idx] = false;
    }
    
    for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << endl;
    return 0;
}

