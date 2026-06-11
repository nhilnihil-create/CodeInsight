#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e11 + 7;
const int mod = 1e9 + 7, maxn = (3 * 1e5) + 10;
const long double PI = acos(-1);

long double fexp(long double a, int b){
    long double ans = 1.0;

    while (b){
        if (b&1) ans = (ans * a);
        a = (a * a);
        b = (b >> 1);
    }

    return ans;
}

int count(int num, int lim){
    int ans = 0;
    while (lim  < num){
        lim*=2;
        ans++;
    }
    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long double ans = 0, n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++){
        long double val = 1.0/n;
        val = (val * fexp(0.5, count(k, i)));
        ans += val;
    }

    cout << fixed << setprecision(10)<<  ans << endl;
    return 0;
}