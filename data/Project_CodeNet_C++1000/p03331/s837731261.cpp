#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 1e9;
    for(int a = 1; a <= n-1; ++a){
        int b = n - a;
        int aa = a;
        int cnt = 0;
        while(aa > 0){
            cnt += aa%10;
            aa /= 10;
        }
        while(b > 0){
            cnt += b%10;
            b /= 10;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
