#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e5 + 5;
const int mod = 998244353;
int a[1<<18],m1[1<<18],m2[1<<18];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int N = (1<<n);
    memset(m2,0xc4,sizeof(m2));
    f(N) {
        cin >> a[i];
        m1[i] = a[i];
    }
    f(n) {
        fr(j,0,N) {
            if (j & (1<<i)) {
                int k = (j ^ (1<<i));
                if (m1[k] > m1[j]) {
                    m2[j] = max({m2[j],m1[j],m2[k]}),m1[j] = m1[k];
                }
                else {
                    m2[j] = max({m2[j],m1[k],m2[k]});
                }
            }
        }
    }
    int ans = 0;
    f1(N-1) {
        ans = max(ans,m1[i] + m2[i]);
        cout << ans << '\n';
    }
}