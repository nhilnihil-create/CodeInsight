#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> c(n),s(n),f(n);
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n) {
        int ans=0;
        repr(j,i,n-1) {
            int chunk=ans/f[j];
            if (ans%f[j]>0) ++chunk;
            ans=max(chunk*f[j]+c[j],s[j]+c[j]);
        }
        cout << ans << endl;
    }
    
    

    return 0;
}
