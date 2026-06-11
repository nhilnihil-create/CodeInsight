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
    string s;
    int q;
    cin >> n >> s >> q;
    rep(qi,q){
        int k;
        cin >> k;
        int sta = -1;
        while(++sta < n){
            if(s[sta] == 'D') break;
        }
        if(sta == n){
            cout << 0 << endl;
            continue;
        }
        int j = min(sta + k, n);
        ll score = 0, cnt_c = 0, cnt_m = 0;
        for(int i = sta; i < j; ++i){
            if(s[i] == 'C'){
                score += cnt_m;
                ++cnt_c;
            }
            if(s[i] == 'M') ++cnt_m;
        }
        ll ans = score;
        for(int i = sta+1; i < n; ++i){
            if(s[i] == 'D'){
                int nj = min(i+k, n);
                for(int l = j; l < nj; ++l){
                    if(s[l] == 'C'){
                        score += cnt_m;
                        ++cnt_c;
                    }
                    if(s[l] == 'M') ++cnt_m;
                }
                ans += score;
                j = nj;
            }
            if(s[i] == 'C') --cnt_c;
            if(s[i] == 'M'){
                score -= cnt_c;
                --cnt_m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
