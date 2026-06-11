#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    if(a+b-1 > n || n > (ll)a*b){
        cout << "-1\n";
        return 0;
    }
    int kp = n;
    vvi ans(a);
    n -= a;
    int st = 1;
    rep(i,a){
        if(n >= b-1){
            ans[i].resize(b);
            rep(j,b-1){
                ans[i][j+1] = b-2+st-j;
            }
            n -= b-1;
            st += b-1;
        }else if(n == 0){
            ans[i].resize(1);
        }else{
            ans[i].resize(n+1);
            rep(j,n){
                ans[i][j+1] = n-1+st-j;
            }
            st += n;
            n = 0;
        }
        ans[i][0] = kp-a+1+i;
    }
    rep(i,a){
        rep(j,len(ans[i])){
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}
