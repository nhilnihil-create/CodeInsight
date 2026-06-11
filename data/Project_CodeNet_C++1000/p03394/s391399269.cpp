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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63\n";
        return 0;
    }else if(n == 4){
        cout << "2 5 20 63\n";
        return 0;
    }else if(n == 5){
        cout << "2 5 20 63 630\n";
        return 0;
    }
    set<int> st;
    int val = 2;
    ll sm = 0;
    rep(i,n){
        while(val % 2 != 0 && val % 3 != 0) val++;
        st.insert(val);
        sm += val++;
    }
    if(sm % 6 == 2){
        st.erase(2), st.insert((val/6+1)*6);
    }else if(sm % 6 == 3){
        st.erase(3), st.insert((val/6+1)*6);
    }else if(sm % 6 == 5){
        st.erase(2);
        while(val % 6 != 3) val++;
        st.insert(val);
    }
    each(it,st){
        if(it == *(--st.end())) break;
        cout << it << " ";
    }
    cout << *(--st.end()) << "\n";
    return 0;
}
