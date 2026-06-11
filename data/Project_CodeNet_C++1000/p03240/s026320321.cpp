#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

vector<pair<int,pair<int,int>>> pmd;
vector<pair<int,int>> lmt;

int main(){
    int n;
    cin >> n;
    rep(i,n){
        int x,y,h;
        cin >> x>> y>> h;
        if(h!=0){
            pmd.push_back(mp(h,mp(x,y)));
        }else{
            lmt.push_back(mp(x,y));
        }
    }
    rep(i,101){
        rep(j,101){
            int x=i;
            int y=j;
            bool ok=1;
            ll hight=pmd[0].fi+abs(pmd[0].se.fi-x)+abs(pmd[0].se.se-y);
            rep(k,pmd.size()){

                ll temp=pmd[k].fi+abs(pmd[k].se.fi-x)+abs(pmd[k].se.se-y);
                if(temp!=hight)ok=0;
            }
            rep(k,lmt.size()){
                ll temp=abs(lmt[k].fi-x)+abs(lmt[k].se-y);
                if(temp<hight)ok=0;
            }
            if(ok){
                cout<<x<<' '<<y<<' '<<hight<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}