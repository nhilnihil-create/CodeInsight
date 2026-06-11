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

const int N = 50 + 5;
const int M = 1e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,k,v[N],ans;

int solve(int a, int b) {

    if(a+1+n-b>k) return 0;

    int rem = k - (a+1+n-b);

    vector<int> x,y;

    int sum = 0;

    for (int i = 0; i <= a; ++i) {
        x.pb(v[i]);
        sum += x.back();
    }

    for (int i = n-1; i >= b; --i) {
        y.pb(v[i]);
        sum += y.back();
    }

    int ret = sum;

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    for (int i = 0; i <= a+1; ++i) {
        for (int j = 0; j <= n-b; ++j) {

            if(rem<i+j) continue;

            int newRet = sum;

            for (int l = 0; l < i; ++l) {
                newRet -= x[l];
            }
            for (int k = 0; k < j; ++k) {
                newRet -= y[k];
            }

            ret = max(ret, newRet);

        }
    }

    return ret;

}

void init() {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = -1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            ans = max(ans, solve(i,j));
        }
    }

    cout << ans << '\n';

    return 0;
}