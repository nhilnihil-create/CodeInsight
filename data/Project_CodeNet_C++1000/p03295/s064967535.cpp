#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INCANT cin.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define out(a) cout << a << endl
#define PRINT(V) for (auto v : (V)) cout << v << " "

const int MOD = 1000000007;
const double PI = acos(-1.0);

void solve() {
    ll N,M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    rep(i, M) cin >> a[i] >> b[i];
    ll count=0;
    while(!a.empty()){
        int min = *min_element(all(b));
        vector<int> aa;
        vector<int> bb;
        rep(i, a.size()){
            if(a[i] >= min){
                aa.push_back(a[i]);
                bb.push_back(b[i]);
            }
        }
        a = aa;
        b = bb;
        count++;
    }
    out(count);
}
int main() {
    INCANT;
    solve();
    return 0;
}


