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
#include <cstring> //memset(dp,0,sizeof(dp))
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
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
    int n,m,q; cin >> n >> m >> q;
    int num[n][n];
    rep(i,n)rep(j,n)num[i][j]=0;
    
    rep(i,m){
        int l,r; cin >> l >> r;
        l--; r--;
        num[l][r]++;
    }
    repp(i,n){
        repp(j,n){
            if(i+1<n)num[i][j]+=num[i+1][j];
        }
    }
    rep(i,n){
        rep(j,n){
            if(j>0)num[i][j]+=num[i][j-1];
        }
    }
    rep(i,q){
        int l,r; cin >> l >> r;
        l--; r--;
        cout << num[l][r] << endl;
    }
}
