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
int dx[5]={-1,0,1,0,0};
int dy[5]={0,-1,0,1,0};
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
    ll h,w,d;cin>>h>>w>>d;
    ll a[310][310];
    map<ll,Pll>address;
    map<Pll,ll>cost;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>a[i][j];
            Pll tmp = mp(i,j);
            address[a[i][j]]=tmp;
        }
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            ll L = a[i][j];
            if(L>d)continue;
            ll co=0;
            ll x=i,y=j;
            ll cnt=0;
            while(L+d<=h*w){
                L+=d;
                cnt++;
                Pll new_place = address[L];
                co+=abs(x-new_place.fi)+abs(y-new_place.se);
                cost[mp(a[i][j],cnt)]=co;
                x=new_place.fi;y=new_place.se;
            }
        }
    }
    ll q;cin>>q;
    while(q--){
        ll L,R;cin>>L>>R;
        ll k=L/d;
        if(L%d==0)k--;
        ll M=L-k*d;
        ll C1=(R-M)/d;
        ll C2=(L-M)/d;
        //cout<<C1<<" "<<C2<<endl;
        cout<<cost[mp(M,C1)]-cost[mp(M,C2)]<<endl;
    }
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



































