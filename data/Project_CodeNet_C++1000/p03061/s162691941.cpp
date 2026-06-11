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
const int INF=2e9;
const double PI=acos(-1);


int gcd(int a,int b) {
    if (a<b) swap(a,b);
    while (b>0) {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> l(n),r(n);
    l[0]=a[0];
    r[n-1]=a[n-1];
    rep(i,n-1) l[i+1]=gcd(l[i],a[i+1]);
    invrep(i,n-1) r[i]=gcd(r[i+1],a[i]);
    int ans=max(l[n-2],r[1]);
    rep(i,n-2) ans=max(ans,gcd(l[i],r[i+2]));
    cout << ans << endl;
    return 0;
}
