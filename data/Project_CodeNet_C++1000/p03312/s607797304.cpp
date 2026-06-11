#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 2e5 + 10;
vector<pair<ll,ll>> options[2][N];

int n;

void add(vector<pair<ll,ll>> opt[], int n, ll x, ll y) {
    if (x == 0 || y == 0) return;
    if (x > y) swap(x,y);
    opt[n].eb(x,y);
}

void compute(const vi &a, vector<pair<ll,ll>> opt[]) {
    int j = 0;
    ll x = 0, y = 0;
    forn(i,n) {
        y += a[i];
        while (j < i && x + a[j] < y - a[j]) {
            x += a[j];
            y -= a[j];
            j++;
        }
        add(opt, i+1, x, y);
        add(opt, i+1, x+a[j], y-a[j]);
    }
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vi a(n);
    forn(i,n) cin >> a[i];
    compute(a,options[0]);
    reverse(all(a));
    compute(a,options[1]);

//    for (int i = 1; i <= n; i++) {
//        cerr << i << ": \n";
//        for (auto xy : options[0][i])
//            cerr << xy.first << ' ' << xy.second << endl;
//    }

    ll ans = 1e18;
    for (int l = 2; l <= n-2; l++) {
        for (auto xy1 : options[0][l]) for (auto xy2 : options[1][n-l]) {
            ll x1, y1; tie(x1,y1) = xy1;
            ll x2, y2; tie(x2,y2) = xy2;
            auto s = max(y1,y2) - min(x1,x2);
            ans = min(ans, s);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
