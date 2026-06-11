//https://atcoder.jp/contests/dwacon5th-prelims/submissions/3656181
#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll solve(int n, string &s, int k){
    int idx = 0;
    while(idx < n){
        if(s[idx] == 'D') break;
        ++idx;
    }
    if(idx == n) return 0;
    int j = min(idx+k, n);
    ll score = 0, cnt_c = 0, cnt_m = 0;
    for(int i = idx; i < j; ++i){
        if(s[i] == 'C'){
            score += cnt_m;
            ++cnt_c;
        }
        else if(s[i] == 'M'){
            ++cnt_m;
        }
    }
    ll res = score;
    for(int i = idx+1; i < n; ++i){
        if(s[i] == 'D'){
            int nj = min(i+k, n);
            for(int ii = j; ii < nj; ++ii){
                if(s[ii] == 'C'){
                    score += cnt_m;
                    ++cnt_c;
                }
                else if(s[ii] == 'M'){
                    ++cnt_m;
                }
            }
            res += score;
            j = nj;
        }
        else if(s[i] == 'C'){
            --cnt_c;
        }
        else if(s[i] == 'M'){
            score -= cnt_c;
            --cnt_m;
        }
    }
    return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, q;
    string s;
    cin >> n >> s >> q;
    rep(i,q){
        int k;
        cin >> k;
        cout << solve(n, s, k) << endl;
    }
	return 0;
}