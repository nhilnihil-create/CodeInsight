#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//template end



int main(){
    int n; scanf("%d",&n);
    vector<int> a(n),b(n),c(n);
    rep(i,0,n)scanf("%d",&a[i]);
    rep(i,0,n)scanf("%d",&b[i]);
    int ans=0;
    rrep(k,29,-1){
        int m=1<<k,cnt=0;
        rep(i,0,n)c[i]=a[i]%m;
        sort(ALL(c));
        rep(i,0,n){
            int d=b[i]%m;
            cnt+=lower_bound(ALL(c),4*m/2-d)-lower_bound(ALL(c),3*m/2-d);
            cnt+=lower_bound(ALL(c),2*m/2-d)-lower_bound(ALL(c),m/2-d);
        }
        ans+=(cnt&1)*m/2;
    }
    printf("%d\n",ans);
    return 0;
}