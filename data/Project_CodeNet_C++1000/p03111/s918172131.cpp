#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
typedef pair<ll,ll> pairs;
vector<pairs> p;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
#define MAX_N 100100
#define MOD 1000000007
bool x[MAX_N];
ll num[MAX_N];
ll fibl[MAX_N]={0};
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll fib(ll a){
    if (fibl[a]!=0)return fibl[a];
    if (a==0){
        return 0;
    }else if (a==1){
        return 1;
    }
    return fibl[a]=fib(a-1)+fib(a-2);
}
 
ll eratosthenes(ll n) {
    int p = 0;
    for (ll i=0; i<=n; ++i) x[i] = true;
    x[0] = x[1] = false;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            p++;
            for(int j=2*i; j<=n; j+=i) x[j] = false;
        }
        
        num[i] = p;
    }
    return p;
}
 
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}
 
ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

void  base_num(ll data,ll base){
    if(data==0) return;
    ll next=abs(data)%abs(base);
    if(data<0) next=(abs(base)-next)%abs(base);
    base_num((data-next)/base,base);
    cout << next;
}

ll nx[9],n,A,B,C;

ll dfs(ll co,ll a,ll b,ll c){
    ll r0,r1,r2,r3;
    if (co==n){
        ll x=30;
        if (min(min(a,b),c)>0){
            return abs(a-A)+abs(b-B)+abs(c-C) -x;
        }else{
            return INF;
        }
    }
    r0=dfs(co+1,a,b,c);
    r1=dfs(co+1,a+nx[co],b,c)+10;
    r2=dfs(co+1,a,b+nx[co],c)+10;
    r3=dfs(co+1,a,b,c+nx[co])+10;
    return min(min(r0,r1),min(r2,r3));
}

int main(){
    cin >> n >> A >> B >> C;
    for (ll i=0;i<n;i++){
        cin >> nx[i];
    }
    cout << dfs(0,0,0,0) << endl;
}
