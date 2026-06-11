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

int ok[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int hoge = 1;
    while(1){
        if(hoge*(hoge-1)/2 >= MAX_N) break;
        ok[hoge*(hoge-1)/2] = hoge;
        hoge++;
    }
    if(ok[n]){
        cout << "Yes\n";
        int cri = ok[n];
        cout << cri << "\n";
        cout << cri-1 << " ";
        rep(i,cri-1){
            cout << i+1 << " ";
        }
        cout << "\n";
        vector<deque<int> > deq;
        deque<int> hoge;
        rep(i,cri-1){
            hoge.pb(i+1);
        }
        deq.pb(hoge);
        int nw = cri;
        rep(i,cri-1){
            cout << cri-1 << " ";
            rep(j,len(deq)){
                cout << deq[j][0] << " ";
                deq[j].pop_front();
            }
            deque<int> hoge;
            rep(j,cri-1-len(deq)){
                cout << nw << " ";
                hoge.pb(nw++);
            }
            deq.pb(hoge);
            cout << "\n";
        }
    }else{
        cout << "No\n";
    }
    return 0;
}
