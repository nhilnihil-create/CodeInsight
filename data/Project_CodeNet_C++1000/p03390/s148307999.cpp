#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;


signed main(){
    int q; cin >> q;
    ll aa[q],bb[q];
    rep(i,q) cin >> aa[i] >> bb[i];
    rep(i,q){
        ll a=aa[i],b=bb[i];
        if(a>b) swap(a,b);
        if(a+1>=b){
            cout << 2*a-2 << endl;
            continue;
        }
        ll x = sqrt(a*b);
        if(x*x==a*b) x--;
        ll ok = 2*x-1;
        if(x*(x+1)>=a*b) ok--;
        cout << ok << endl;
    }
}
