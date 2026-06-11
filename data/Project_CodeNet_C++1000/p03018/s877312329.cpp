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
#define EPS (1e-10)
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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp(pair<ll,Pll> a,pair<ll,Pll> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se.fi>b.se.fi;
}
//----------------------------------------------------------------------
string s;
ll n;
ll ans=0;
/*ll i;
void dfs1(int j){
    if(s[j]=='A'){
        ans++;
        s[j]='B';
        s[j+1]='C';
        s[j+2]='A';
        if(j>0){
            dfs1(j-1);
        }
    }
}
void dfs2(){
    if(s[i+1]=='B'&&s[i+2]=='C'){
        ans++;
        s[i]='B';
        s[i+1]='C';
        s[i+2]='A';
        if(i<n-4){
            i+=2;
            dfs2();
        }
    }
}*/
//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //-------------------------------
    cin>>s;
    n=s.length();
    /*or(i=0;i<n-2;i++){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
            ans++;
            s[i]='B';
            s[i+1]='C';
            s[i+2]='A';
            if(i>0){
                dfs1(i-1);
            }
            else if(i<n-4){
                i+=2;
                dfs2();
            }
        }
    }*/
    ll cnta=0;
    for(ll i=0;i<n-2;i++){
        if(s[i]=='A'){
            cnta++;
            if(s[i+1]=='B'&&s[i+2]=='C'){
                ll cntbc=1;
                ll lastj=i+2;
                for(ll j=i+3;j<n-1;j+=2){
                    if(s[j]=='B'&&s[j+1]=='C'){
                        cntbc++;
                        lastj=j+1;
                    }
                    else break;
                }
                ans+=cnta*cntbc;
                i=lastj;
            }
        }
        else cnta=0;
    }
    cout<<ans<<endl;
    //-------------------------------  
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------





































