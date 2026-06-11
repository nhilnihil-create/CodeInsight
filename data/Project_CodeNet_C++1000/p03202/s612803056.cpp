#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC target("avx")
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

const int MAX_N = 200005;

int n, a[MAX_N];

bool possible(int cri)
{
    vector<int> id, val;
    int prv = 0;
    rep(i,n){
        if(a[i] <= prv){
            int num = id.end() - upper_bound(all(id),a[i]);
            rep(j,num){
                id.pop_back(), val.pop_back();
            }
            int ind = lower_bound(all(id),a[i]) - id.begin();
            if(ind == len(id)){
                id.pb(a[i]), val.pb(1);
                prv = a[i];
                continue;
            }
            while(true){
                // id[ind] が今見ている桁
                int ima = id[ind];
                if(val[ind] < cri-1){
                    val[ind]++;
                    break;
                }
                id.pop_back(), val.pop_back();
                if(ind == 0){
                    if(ima == 1) return false;
                    id.pb(ima-1), val.pb(1);
                    break;
                }
                if(id[ind-1] < ima-1){
                    id.pb(ima-1), val.pb(1);
                    break;
                }
                ind--;
            }
        }
        prv = a[i];
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int prv = -1;
    rep(i,n){
        cin >> a[i];
        if(prv >= a[i]){
            prv = INF;
        }else{
            prv = a[i];
        }
    }
    if(prv != INF){
        cout << "1\n";
        return 0;
    }
    int l = 1, r = n;
    while(r-l>1){
        int mid = (l+r)/2;
        if(possible(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << "\n";
    return 0;
}