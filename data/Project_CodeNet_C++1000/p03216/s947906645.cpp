#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

template<class T,class U> void chmax(T& a, U b) {if(a<b)a=b;}
template<class T,class U> void chmin(T& a ,U b) {if(b<a)a=b;}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n,q;
    string s;
    cin >> n >> s >> q;

    while(q--) {
        int k;
        cin >> k;

        ll d,m,dm;
        d = m = dm = 0;

        ll ans = 0;
        rep(i, n) {
            if (s[i] == 'D') {
                d++;
            } else if (s[i] == 'M') {
                m++;
                dm += d;
            }

            if (i >= k) {
                if (s[i - k] == 'D') {
                    d--;
                    dm -= m;
                } else if (s[i - k] == 'M') {
                    m--;
                }
            }

            if (s[i] == 'C') ans += dm;
        }

        cout << ans << endl;
    }
    return 0;
}
