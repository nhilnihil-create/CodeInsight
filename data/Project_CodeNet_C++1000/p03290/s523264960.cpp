//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 5000 + 5;
const int M = 5e5 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int d,g,p[10],c[10],ans=OO;

bool isOn(int bit, int mask) {

    return (1<<bit)&mask;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> g;

    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }

    for (int mask = 0; mask < (1<<d); ++mask) {

        int cur = 0, cnt = 0;

        for (int bit = 0; bit < d; ++bit) {

            if(isOn(bit,mask)) {

                cnt += p[bit];
                cur += 100*(bit+1)*p[bit] + c[bit];

            }

        }

        for (int bit = d - 1; ~bit ; --bit) {

            if(!isOn(bit,mask)) {

                for (int i = 0; i < p[bit] && cur < g; ++i) {

                    cur += 100*(bit+1);
                    ++cnt;

                }

            }

        }

        ans = min(ans, cnt);

    }

    cout << ans << '\n';

    return 0;
}