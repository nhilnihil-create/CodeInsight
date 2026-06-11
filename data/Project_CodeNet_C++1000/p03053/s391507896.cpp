//g++ main.cpp -I /usr/local/include/ac-library
#include<cmath>
//#include <atcoder/all>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
//using namespace atcoder;
stack<int> st;
queue<int> qu;
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
#define pb push_back
#define sz(x) (int)(x).size()
#define mod 1000000007
//#define mint=modint1000000007
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

int node[1000005];
vector<int> to[1000005];
vector<int> du={-1,0,1,0};
vector<int> dw={0,-1,0,1};
vector<int> b;

int main(){
    int h,w;
    cin >> h>> w;
    vector<string> A(h);
    rep(i,h){
        cin >> A[i];
    }
    rep(i,h){
        rep(j,w){
            node[i*1000+j]=INF;
        }
    }
    
    rep(i,h){
        rep(j,w){
            int u=i*1000+j;
            if(A[i][j]=='#'){
                b.push_back(i*1000+j);
            }
            rep(k,4){
                int y=i+du[k];
                int x=j+dw[k];
                if(0<=x&&x<w&&0<=y&&y<h){
                    int v=y*1000+x;
                    to[u].push_back(v);
                    //to[v].push_back(u);
                }
            }
        }
    }
    //cerr<<1<<endl;
    rep(i,sz(b)){
        // BFS
        qu.push(b[i]);
        node[b[i]]=0;
    }
        
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        for(int v:to[u]){
            if(node[v]>node[u]+1){
                node[v]=node[u]+1;
                qu.push(v);
            }
        }
        //cerr<<2<<endl;
    }
    int ans=0;
    rep(i,h){
        rep(j,w){
            if(node[i*1000+j]>ans){
                ans=node[i*1000+j];
            }
            //ans=max(ans,node[i*h+j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}