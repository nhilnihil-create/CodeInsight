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

const int MAX_N = 200005;

int n, a[MAX_N];

bool possible(int cri)
{
    map<int,int> mp;
    int prv = 0;
    rep(i,n){
        if(a[i] <= prv){
            mp.erase(mp.upper_bound(a[i]), mp.end());
            rrep(j,a[i]+1){
                if(j == 0){
                    return false;
                }
                if(mp[j] < cri-1){
                    mp[j]++;
                    break;
                }else{
                    mp.erase(j);
                }
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
    int flag = -1;
    rep(i,n){
        cin >> a[i];
        if(flag >= a[i]){
            flag = INF;
        }
        cmx(flag, a[i]);
    }
    if(flag != INF){
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