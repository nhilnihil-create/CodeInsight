#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 100000000000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl


signed main(){
    int N;
    int a[214514],b[214514];
    cin >> N;
    REP(i,N){
        cin >> a[i];
    }
    REP(i,N){
        cin >> b[i];
    }
    int Ans=0;
    RREP(k,30){
        REP(i,N)a[i]%=(2ll<<k);
        REP(i,N)b[i]%=(2ll<<k);
        sort(a,a+N);
        sort(b,b+N);
        ll sum=0;
        ll T=1<<k;
        REP(i,N){
            if(a[i]>=T){
                sum+=lower_bound(b,b+N,2*T-a[i])-b+N;
                sum-=lower_bound(b,b+N,3*T-a[i])-b;
            }else{
                sum+=lower_bound(b,b+N,2*T-a[i])-b;
                sum-=lower_bound(b,b+N,T-a[i])-b;
            }
        }
        //cout << sum << Endl;
        if(sum%2==1){
            Ans+=T;
        }
    }
    cout << Ans << endl;
    return 0;
}
