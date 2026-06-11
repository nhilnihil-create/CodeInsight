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
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 100000000
#define INF 300000000000000000
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_time=clock();
    //-------------------------------
    ll n,m;cin>>n>>m;
    V<ll>x(n),y(n),z(n);
    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    ll ans=-INF;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                V<ll>v(n);
                for(ll q=0;q<n;q++){
                    if(i==0)v[q]+=x[q];
                    else v[q]-=x[q];
                    if(j==0)v[q]+=y[q];
                    else v[q]-=y[q];
                    if(k==0)v[q]+=z[q];
                    else v[q]-=z[q];
                }
                sort(all(v));
                reverse(all(v));
                ll tmp=0;
                for(ll q=0;q<m;q++)tmp+=v[q];
                chmax(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



































