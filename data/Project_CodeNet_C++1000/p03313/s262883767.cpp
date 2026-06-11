#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;




int main(){
    int n;cin >> n;
    vector<LL> a(1<<n);
    for (int i = 0; i < (1<<n); i++) {
        cin >> a[i];
    }
    vector<P> dp(1<<n,P(-1,-1));
    for (int k = 0; k < (1<<n); k++) {
        vector<P> t;
        t.pb(P(a[k],k));
        for (int i = 0; i < n; i++) {
            if(k&(1<<i)){
                P p = dp[k-(1<<i)];
                if(p.fs!=-1) t.pb(P(a[p.fs],p.fs));
                if(p.sc!=-1) t.pb(P(a[p.sc],p.sc));
            }
        }
        sort(ALL(t),greater<P>());
        t.erase(unique(ALL(t)),t.end());
        if(t.size()>=2) dp[k]=P(t[0].sc,t[1].sc);
        else if(t.size()==1) dp[k]=P(t[0].sc,-1);
    }
    LL ans = 0;
    for (int i = 1; i < (1<<n); i++) {
        ans = max(ans,a[dp[i].fs]+a[dp[i].sc]);
        cout << ans << endl;
    }
    return 0;
}

