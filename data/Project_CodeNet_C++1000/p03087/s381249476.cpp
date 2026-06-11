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
    int n, q;
    string s;
    cin >> n >> q >> s;
    s += "!";
    vector<int> cnt(n+2, 0);
    rep(i,n){
        cnt[i+1] = cnt[i];
        if(s[i] == 'A' && s[i+1] == 'C') cnt[i+1]++;
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        --l; --r;
        int ans = cnt[r] - cnt[l];
        cout << ans << endl;
    }
	return 0;
}
