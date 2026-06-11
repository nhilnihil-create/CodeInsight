#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 998244353;

const int maxn = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        if (k) {
            cout << -1 << '\n';
        }
        else {
            cout << "0 0 1 1\n";
        }
        exit(0);
    }
    n = 1 << (n);
    if (k >= (n)) {
        cout << -1 << '\n';
        exit(0);
    }
    n <<= 1;
    int ans[n + 5] = {};
    ans[n/2] = ans[n] = k;
    for (int p = 0, i = 1 ; i < n/2 ; i++,p++) {
        if (p == k) {
            ++p;
        }
        ans[i] = ans[n-i] = p;
    }
    f1(n) {
        cout << ans[i] <<' ';
    }
    cout << '\n';
}