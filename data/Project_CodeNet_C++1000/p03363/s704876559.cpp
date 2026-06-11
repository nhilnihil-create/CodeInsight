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
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using graph = vector<vector<int>>;
using P = pair<int,int>;
ll MAX(ll a,ll b,ll c){return max(a,max(b,c));}
ll MIN(ll a,ll b,ll c){return min(a,min(b,c));}
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    int n;
    cin >> n;
    n++;
    ll num[n]={0};
    ll cum[n]={0};
    rep1(i,n-1){
        cin >> num[i];
        cum[i] = cum[i-1] + num[i];
    }
    sort(cum,cum+n);
    vector<ll> count(220000,0);
    ll k = 0;
    ll p = 0;
    rep(i,n){
        if(p == cum[i]){
            count[k]++;
        }
        else{
            k++;
            p = cum[i];
            count[k]++;
        }
    }
    ll ans = 0;
    rep(i,k+1){
        ans += count[i]*(count[i]-1)/2;
    }
    cout << ans << endl;
}