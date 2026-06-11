#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 1<<30
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef long long int LL;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//---------------------------------------------------------------------------
struct unionfind{
    vector<int> rank,parent,size;
    unionfind(int n){
        for(int i=0;i<n;i++){
            rank.push_back(1);//树的高度
            parent.push_back(i);//根
            size.push_back(1);//树大小
        }
    }
    int getroot(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=getroot(parent[x]);//押平路径加速以后的查找
    }
    bool issame(int a,int b){
        return getroot(a)==getroot(b);
    }
    void unite(int a,int b){
        a=getroot(a);
        b=getroot(b);
        if(a==b)
            return;
        else if(rank[a]>rank[b]){ //合并到高的树下
            parent[b]=a;
            size[a]+=size[b];
        }
        else if(rank[a]==rank[b]){
            parent[b]=a;
            rank[a]++;
            size[a]+=size[b];
        }
        else{
            parent[a]=b;
            size[b]+=size[a];
        }
    }
};

//---------------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    vector<int>a(3),b(3);cin>>a[0]>>b[0]>>a[1]>>b[1]>>a[2]>>b[2];
    map<int,int>m;
    for(int i=0;i<4;i++){
        m[a[i]]++;
        m[b[i]]++;
    }
    for(int i=1;i<=4;i++){
        if(m[i]>2){cout<<"NO"<<endl;
            return 0;}
    }
    cout<<"YES"<<Endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------

/*
ll n;cin>>n;
vector<ll>a(n);
for(ll i=0;i<n;i++)
    cin>>a[i];
 
ll n;cin>>s;
string s;cin>>s;

ll n,m;cin>>n>>m;
vector<ll>a(n),b(m);
for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<m;i++){
    cin>>b[i];
}

ll n;cin>>n;
vector<Pll>xy;
for(ll i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    xy.pb({x,y});
}
*/
