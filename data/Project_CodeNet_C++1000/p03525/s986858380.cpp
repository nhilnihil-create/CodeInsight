#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
    for(auto i=begin(v); i != end(v); ++i){
        if(i !=begin(v)) os << ' ';
        os << *i;
    }
    return os;
}

ll N,D[52],ma=-1,X=0;

void hantei(ll chek[]){
    ll mi = INF,T=0;
    Rep(i,1,25){
        if(chek[i%24]==0){
            T++;
        }
        else{
            mi=min(T+1,mi);
            T=0;
        }
    }
    ma=max(ma,mi);
}

void dfs(ll key,ll chek[]){
    if(key==N){
        hantei(chek);
        return;
    }
    if(chek[D[key]]==1 && chek[24-D[key]]==1){
        X=1;
        return;
    }
    if(chek[D[key]]==0){
        chek[D[key]]=1;
        dfs(key+1,chek);
        chek[D[key]]=0;
    }
    if(chek[24-D[key]]==0){
        chek[24-D[key]]=1;
        dfs(key+1,chek);
        chek[24-D[key]]=0;
    }
}

int main(){
    ll chek[50];
    cin >> N;
    rep(i,24){
        chek[i]=0;
    }
    chek[0]=1;
    chek[24]=1;
    rep(i,N){
        cin >> D[i];
    }
    dfs(0,chek);
    cout << (X==1 ? 0 : ma ) << endl;
}