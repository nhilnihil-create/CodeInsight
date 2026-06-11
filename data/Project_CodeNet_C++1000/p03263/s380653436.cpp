#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=max(x,a)
#define chmin(x,a) x=min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<int> >;//ll or Edge
using Edge=pair<int,ll>;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// sort_reverse...greater<ll>()
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17

typedef pair<P,P> PP;
int main(){
    int H,W;cin>>H>>W;
    vector<VI> a(H, VI(W,0));
    int odd=0;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        cin>>a[i][j];
        if(a[i][j]&1)++odd;
    }
    vector<PP>res;
    int num=0;
    int x=0,y=0;
    for(int iter=0;iter<W*H;iter++){
        if(a[x][y]%2==1)num++;
        int nx=x,ny=y;
        if(x%2==0){
            if(ny==W-1)nx++;
            else ny++;
        }
        else {
            if(ny==0)nx++;
            else --ny;
        }
        if(num%2==1)if(num<odd)res.push_back(PP(P(x,y),P(nx,ny)));
        x=nx,y=ny;
    }
    cout<<res.size()<<endl;
    for(auto p:res){
        cout<<p.fi.fi+1<<" "<<p.fi.se+1<<" "<<p.se.fi+1<<" "<<p.se.se+1<<endl;
    }
return 0;
}