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
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1e9;
    rep(i,n-k+1){
        int left = x[i];
        int right = x[i+k-1];
        if(left < 0 && right < 0) chmin(ans, -left);
        else if(left < 0 && right >= 0){
            if(-left < right) chmin(ans, right-2*left);
            else chmin(ans, 2*right-left);
        }
        else if(left >= 0 && right >= 0) chmin(ans, right);
    }
    cout << ans << endl;
	return 0;
}