#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=100005;
//i_am_noob
int n,cnt=0,pow3[maxn],sum[maxn][4],ans=0,x;
string str;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> str;
    n=sz(str);
    rep(n) cnt+=str[i]=='?';
    pow3[0]=1;
    rep(maxn-1) pow3[i+1]=pow3[i]*3%MOD;
    rep(4) sum[0][i]=0;
    rep(n) sum[i+1][0]=sum[i][0]+(str[i]=='A');
    rep(n) sum[i+1][1]=sum[i][1]+(str[i]=='?');
    rep(n) sum[i+1][2]=sum[i][2]+(str[n-1-i]=='C');
    rep(n) sum[i+1][3]=sum[i][3]+(str[n-1-i]=='?');
    rep(n){
        if(str[i]=='B'||str[i]=='?'){
            if(str[i]=='B') x=0;
            else x=1;
            if(cnt>=x) ans=add(ans,sum[i][0]*sum[n-1-i][2]%MOD*pow3[cnt-x]%MOD);
            if(cnt>=x+1) ans=add(ans,sum[i][1]*sum[n-1-i][2]%MOD*pow3[cnt-x-1]%MOD);
            if(cnt>=x+1) ans=add(ans,sum[i][0]*sum[n-1-i][3]%MOD*pow3[cnt-x-1]%MOD);
            if(cnt>=x+2) ans=add(ans,sum[i][1]*sum[n-1-i][3]%MOD*pow3[cnt-x-2]%MOD);
        }
    }
    print1(ans);
	return 0;
}
