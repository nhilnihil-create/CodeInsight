#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define akumanosuuji = 666;
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
ll MAX(ll a,ll b,ll c){return max(a,max(b,c));}
ll MIN(ll a,ll b,ll c){return min(a,min(b,c));}
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    int n,d,x,ans=0;
    cin >> n >> d >> x;
    int a[n];
    rep(i,n){
        cin >> a[i];
        ans += (d+a[i]-1) / a[i];
    }
    cout << ans + x << endl;
}