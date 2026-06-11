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
    int n;
    cin >> n;
    vl x(n), y(n);
    ll flag = -1;
    rep(i,n){
        cin >> x[i] >> y[i];
        if(flag < 0){
            flag = abs(x[i]+y[i])%2;
        }else if(abs(x[i]+y[i])%2 != flag){
            cout << "-1\n";
            return 0;
        }
    }
    ll nw = 1;
    if(flag){
        cout << "40\n";
        rep(i,40){
            cout << nw << " ";
            nw *= 2;
        }
        cout << "\n";
    }else{
        cout << "40\n";
        cout << nw << " ";
        rep(i,39){
            cout << nw << " ";
            nw *= 2;
        }
        cout << "\n";
    }
    rep(i,n){
        if(!flag) cout << 'R', x[i]--;
        string s;
        ll val = nw / 2;
        while(val){
            if(y[i] > x[i]){
                if(y[i] > -x[i]){
                    s.pb('U');
                    y[i] -= val;
                }else{
                    s.pb('L');
                    x[i] += val;
                }
            }else{
                if(y[i] > -x[i]){
                    s.pb('R');
                    x[i] -= val;
                }else{
                    s.pb('D');
                    y[i] += val;
                }
            }
            val /= 2;
        }
        reverse(all(s));
        cout << s << "\n";
    }
    return 0;
}
