#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;


int main(){
    int n; cin >> n;
    ll l=0, l0=2,l1=1;
    ll ans=0;
    rep(i, n-1){
        ans = l0 + l1;
        l0 = l1;
        l1 = ans;
    }
    
    out(l1);
}