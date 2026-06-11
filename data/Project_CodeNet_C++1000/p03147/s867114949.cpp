#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<int> H(n); rep(i, n) cin >> H[i];
    int cnt = 0;

    for(int i=100; i>0; i--){
        bool water = false;
        for(int j=0; j<n; j++){
            if(!water && H[j] == i){
                water = true;
                cnt++;
                H[j]--;
            }else if(water && H[j] == i) H[j]--;
            else if(water && H[j] != i){
                water = false;
            }
        }
    }
    cout << cnt << ln;
}
