#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, ll> pcl;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(mp(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define mp make_pair
#define pb push_back
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    int n, prex, prey, pret, difft, diffxy;
    int t[100005], x[100005], y[100005];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    prex = 0, prey = 0, pret = 0;
    for(int i = 0; i < n; i++) {
        difft = t[i] - pret;
        diffxy = x[i] - prex + y[i] - prey;
        if(diffxy < 0) {
            diffxy *= -1;
        }
        if(difft < diffxy) {
            cout << "No" << endl;
            exit(0);
        }
        if(difft % 2 == 1) {
            if(diffxy % 2 != 1) {
                cout << "No" << endl;
                exit(0);
            }
        } else {
            if(diffxy % 2 != 0) {
                cout << "No" << endl;
                exit(0);
            }
        }
        pret = t[i], prex = x[i], prey = y[i];
    }
    cout << "Yes" << endl;
    return 0;
}