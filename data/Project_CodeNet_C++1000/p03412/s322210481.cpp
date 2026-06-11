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

const int BIT = 29;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n), b(n);
    vvi sb(BIT, vi(n));
    vi sm(BIT, 0);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
        rep(j,BIT){
            sb[j][i] = (((1 << j) - 1) & b[i]);
            sm[j] += ((b[i] >> j) & 1);
        }
    }
    int ans = 0;
    rep(i,BIT){
        int res = 0;
        sort(all(sb[i]));
        rep(j,n){
            int ch = sm[i];
            int mask = (((1 << i) - 1) & a[j]);
            int comp = (1 << i) - mask;
            int cnt = n - (lower_bound(all(sb[i]),comp) - sb[i].begin());
            if((a[j] >> i) & 1){
                ch += n-cnt;
            }else{
                ch += cnt;
            }
            res ^= ch % 2;
        }
        ans += (res << i);
    }
    cout << ans << "\n";
    return 0;
}