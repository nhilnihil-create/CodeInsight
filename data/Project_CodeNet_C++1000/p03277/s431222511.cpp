#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

struct BIT{
    ll N;
    vector<ll> dat;
    void initialize(ll _n){N=_n+1;dat.resize(N+1);rep(i,N+1)dat[i]=0;}
    ll sum(ll i){ll s=0;while(i>=0)s+=dat[i],i=(i&(i+1))-1;return s;}
    ll sum_between(ll i,ll j){return i<=j?sum(j)-sum(i-1):0;}
    void add(ll i,ll x){while(i<=N)dat[i]+=x,i|=i+1;}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;
    cin>>N;
    vector<int> A(N), AS(N);
    rep(i,N) cin>>A[i],AS[i]=A[i];
    sort(all(AS));
    
    int ub=N, lb=0;
    BIT bit;
    ll border=((N*(N+1)/2)+1)/2;
    while(ub-lb>1){
        int mid=(ub+lb)/2, midn=AS[mid];
        bit.initialize(2*N+1);
        int sum=0;
        bit.add(N,1);
        ll result=0;
        rep(i,N){
            sum+=A[i]>=midn?1:-1;
            result+=bit.sum(sum+N);
            bit.add(sum+N,1);
        }
        if(result>=border) lb=mid;
        else ub=mid;
    }
    cout1(AS[lb]);
}