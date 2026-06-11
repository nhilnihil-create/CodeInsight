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
int G[104];
int main(){
    int n;
    cin >> n;
    vector<int> F[n];
    rep(i,n){
        rep(j,10){
            int f;
            cin >> f;
            F[i].push_back(f);
        }
    }
    int p[n][11];
    rep(i,n){
        rep(j,11){
            cin >> p[i][j];
            //cerr<<p[i][j]<<' ';
        }
        //cerr<<endl;
    }
    ll ans=-INF;
    for(int i=1;i<=pow(2,10)-1;i++){
        rep(j,n){G[j]=0;}
        ll temp=0;
        rep(j,10){
            if((i>>j)&1==1){
                rep(k,n){
                    if(F[k][j]==1){
                        G[k]++;
                    }
                }
            }
        }
        rep(j,n){
            temp+=p[j][G[j]];
            /*
            if(i==32){
                cerr<<G[j]<<' '<<p[j][G[j]]<<' ';
            }
            */
            //cerr<<G[j]<<' ';
        }
        //cerr<<endl;
        if(ans<temp){
            ans=temp;
            //cerr<<temp<<' '<<i<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}