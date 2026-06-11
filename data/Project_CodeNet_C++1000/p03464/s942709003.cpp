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
    int k; cin >> k;
    ll a[k];
    rep(i,k) cin >> a[i];
    ll amin=2,amax=2;
    rrep(i,k){
        amin=(amin+a[i]-1)/a[i]*a[i];
        if(amin>amax){
            cout << -1 << endl;
            return 0;
        }
        amax=(amax/a[i]+1)*a[i]-1;
    }
    cout << amin << " " << amax << endl;

}
