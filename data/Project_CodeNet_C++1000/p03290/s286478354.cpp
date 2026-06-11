#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep1(i,n) for(int i=1; i<=(int)(n); i++)
#define all(c) c.begin(),c.end()
#define psb push_back
#define ppb pop_back

const int INF = 1000000000;

int main() {
    int D, G;
    cin >> D >> G;

    vi p(D);
    vi c(D);

    rep (i, D) {
        cin >> p[i] >> c[i];
    }

    int ans = INF;
    rep (i, 1 << D) {
        int s = 0, n = 0, m = -1;
        rep (j, D) {
            if ((i >> j) & 1) {
                s += 100*(j+1)*p[j]+c[j];
                n += p[j];
            } else {
                m = j;
            }
        }

        if (s < G) {
            rep (j, p[m]) {
                s += 100*(m+1);
                n++;
                if (s >= G) {
                    ans = min(ans, n);
                    break;
                }
            }
        } else {
            ans = min(ans, n);
        }
    }

    cout << ans << endl;
}
