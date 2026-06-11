//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 100 + 5;
const int OO = 2e9;

int n,f[N][11],p[N][12],c[N],ans;

void init() {



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    ans = -OO;

    for(int i=0;i<n;++i) {

        for(int j=0;j<10;++j) {

            cin >> f[i][j];

        }

    }

    for(int i=0;i<n;++i) {

        for(int j=0;j<11;++j) {

            cin >> p[i][j];

        }

    }

    for(int i=1;i<(1<<10);++i) {

        int curBit = i;

        int sum = 0;

        memset(c,0,sizeof(c));

        for(int j=0;j<10;++j) {

            if(curBit&1) {

                for(int k=0;k<n;++k) {

                    if(f[k][j]) c[k]++;

                }

            }

            curBit /= 2;

        }

        for(int k=0;k<n;++k) {

            sum += p[k][c[k]];

        }

        ans = max(ans,sum);

    }

    cout << ans << '\n';

    return 0;

}