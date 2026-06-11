#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int d[501][501];

int main(){
    int n, m, Q;
    cin >> n >> m >> Q;
    int l, r;
    rep(i, m) {
        cin >> l >> r;
        rep(j, 500-r+1) {
            d[l-1][j+r-1]++;
        }
    }
    int p, q;
    ll sum = 0;
    rep(i, Q) {
        cin >> p >> q;
        for(int j = p-1; j < q; j++) {
            //for(int k = j; k < q; k++) {
                sum += d[j][q-1];
                //cout << j << " " << d[j][q-1] << endl;
            //}
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}