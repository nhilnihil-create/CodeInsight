#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s; cin >> s;
    if(s.size()==1)cout << s[0] - '0' << ln;
    else{
    int nine = count(all(s), '9');
    if(nine == s.size())cout << (ll)s.size() * 9 << ln;
    else{
        ll sum = 0;
        rep(i, s.size())sum+=s[i] -'0';
        ll res = s[0] - '1';
        rept(i, 1, s.size()){
            res += 9;
        }
        chmax(res, sum);
        cout << res << ln;
    }
    }
}
