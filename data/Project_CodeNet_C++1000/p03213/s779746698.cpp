#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for(ll i=2; i*i<=n; i++) {
        if (n % i) continue;
        res.emplace_back(i, 0);
        while (n%i == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    map<ll, int> facmap;
    for(int i=1; i<=n;i++){
        vector<pair<ll, int>> tmp = factorize(i);
        for(auto a : tmp){
            facmap[a.first] += a.second;
        }
    }
    int p = 0, q = 0, r = 0, s=0, t=0;
    for(auto a : facmap){
    //    cerr<<a.first<<" "<<a.second<<endl;
        if(a.second >= 74){
            t++;
        }
        if(a.second >= 24){
            s++;
        }
        if(a.second >= 14){
            r++;
        }
        if(a.second >= 4){
            q++;
        }
        if(a.second >= 2){
            p++;
        }
    }
    ll ans = q*(q-1)*(p-2)/2 
          +  r * (q-1)
          + s*(p-1)
          + t;
    cout<<ans<<endl;
 }