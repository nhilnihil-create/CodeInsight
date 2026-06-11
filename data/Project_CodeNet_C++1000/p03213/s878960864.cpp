#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) << num << endl;
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

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n % 2 == 0 || n % 3 == 0) return false;
    // n は 2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }

    return true;
}

signed main(){
    int n; cin >> n;
    int num[n];
    rep(i,n) num[i]=0;
    for(int i=1;i<=n;i++){
        if(is_prime(i)){
            int j=i;
            while(n/j>0){
                num[i]+=n/j;
                j*=i;
            }
        }
    }
    ll n3=0,n5=0,n15=0,n25=0,n75=0;
    rep(i,n){
        if(num[i]>1) n3++;
        if(num[i]>3) n5++;
        if(num[i]>13) n15++;
        if(num[i]>23) n25++;
        if(num[i]>73) n75++;
    }
    ll ans=(n3-n5)*n5*(n5-1)/2;
    ans+=n5*(n5-1)*(n5-2)/2;
    
    ans+=(n3-n25)*n25;
    ans+=n25*(n25-1);
    
    ans+=(n5-n15)*n15;
    ans+=n15*(n15-1);
    
    ans+=n75;
    
    cout << ans << endl;
}

