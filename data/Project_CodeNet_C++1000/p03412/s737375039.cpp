#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    
    int ans = 0;

    srep(i,1,30){
        int f[n], g[n];
        rep(j,n){
            f[j] = a[j] % (1<<i);
            g[j] = b[j] % (1<<i);
        }
        sort(g,g+n);
        ll cnt = 0;
        rep(j,n){
            cnt += g+n - lower_bound(g,g+n,3*(1<<(i-1))-f[j]);
            cnt += lower_bound(g,g+n,2*(1<<(i-1))-f[j]) - lower_bound(g,g+n,1*(1<<(i-1))-f[j]);
        }   
        if(cnt % 2 == 1){
            ans += (1<<(i-1));
        }
    }

    cout << ans << endl;
    return 0;
}


