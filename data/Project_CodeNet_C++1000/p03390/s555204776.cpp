#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <bitset>
#include <utility>
#include <complex>
#include <assert.h>
#include <limits.h>
//#include <bits/stdc++.h>
using namespace std;
#define rank rankk
#define mp make_pair
#define pb push_back
#define xo(a,b) ((b)&1?(a):0)
#define tm tmp

//#define LL ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,ll>pil;
typedef pair<ll,ll> pll;
//const double INF=1e20;
const int INF=0x3f3f3f3f;
//const int INF= 0x7fffffff;
//const ll INF=0x3f3f3f3f3f3f3f3fll;
const ll INFF=0x3f3f3f3f3f3f3fll;
//const ll INFF=1e14+5;
const int MAX=5e5+5;
//const ll MAXN=2e8;
//const int MAX_N=MAX;
//const ll MOD=1e9+7;
const ll MOD=1e9+7;
//const long double pi=acos(-1.0);
//const double eps=0.00000001;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
//#define double long double
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
inline ll powMM(ll a,ll b,ll M){
    ll ret=1;
    a%=M;
//    b%=M;
    while (b){
        if (b&1) ret=ret*a%M;
        b>>=1;
        a=a*a%M;
    }
    return ret;
}
//const long double eps=-1.0;
//clock_t t1 = clock();
//fprintf(stderr, "%ld ms\n", clock() - t1);
void open()
{
    freopen("in2.txt","r",stdin);
    freopen("out2.txt","w",stdout);
}

int q;
ll a,b,da;
bool check(ll len)
{
    ll x,y;
    for(ll i=len/2-10;i<=len/2+10&&i<=len;i++)
    {
        if(i<1)continue;
        x=(i>=a?i+1:i);
        ll tem=len+1-i;
        y=(tem>=b?tem+1:tem);
        if(x*y>=da)return false;
    }
    return 1;
}
ll solve()
{
    ll l=0,r=a+b,re=0,mid;
    while(l<=r)
    {
        mid=(l+r)>>1LL;
        if(check(mid))re=mid,l=mid+1;
        else r=mid-1;
    }
    return re;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        da=a*b;
        printf("%lld\n",solve());
    }
}
/*

*/
