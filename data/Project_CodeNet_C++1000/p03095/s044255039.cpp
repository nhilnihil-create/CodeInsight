#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const int MOD = 1e9+7;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vecl cnt(26);
    for(char c : S) cnt[(int)c-'a']++;
    ll ans = 1;
    REP(i,26) {
        //Scout << cnt[i] << endl;
        if(cnt[i] > 0) {
            ans *= cnt[i]+1;
            ans %= MOD;
        }
    }
    cout << ans-1 << endl;
}