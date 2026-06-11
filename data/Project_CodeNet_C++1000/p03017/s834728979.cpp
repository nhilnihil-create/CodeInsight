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
   int n, a, b, c, d; cin >> n >> a >> b >> c >> d; a--, b--, c--, d--;
   string s; cin >> s;
    bool renzoku = false;
    rept(i, min(a, b), max(c, d)){
        if(s[i]=='#' && s[i+1] == '#')renzoku = true;
    }
    if(renzoku)cout << "No" << ln;
    else if(c<d)cout << "Yes" << ln;
    else{
        bool three = false;
        rept(i, b, d+1){
            if(s[i]=='.' && s[i+1] == '.' && s[i-1] == '.')three = true;
        }
        if(three)cout << "Yes" << ln;
        else cout << "No" << ln;
    }
}
