#include <bits/stdc++.h>
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
#define ll __int128
#define int ll

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

int cnt(ll val)
{
    int res = 0;
    while(val){
        res += val % 10;
        val /= 10;
    }
    return res;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long K;
    cin >> K;
    vl vec;
    ll val = 1;
    rep(i,3){
        srep(j,2,11){
            vec.pb(val*j-1);
        }
        val *= 10;
    }
    rep(i,14){
        srep(j,1,10){
            srep(k,1,101){
                vec.pb(val*j+val/100*k-1);
            }
        }
        val *= 10;
    }
    sort(all(vec));
    vi num(len(vec));
    rep(i,len(vec)){
        num[i] = cnt(vec[i]);
    }
    rep(i,len(vec)){
        bool ok = true;
        srep(j,i+1,len(vec)){
            if(vec[j]*num[i] < vec[i]*num[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << (long long)vec[i] << "\n";
            K--;
            if(K == 0){
                break;
            }
        }
    }
    return 0;
}
