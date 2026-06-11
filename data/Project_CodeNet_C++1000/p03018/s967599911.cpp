#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(std::string s){
    i64 ans = 0, cnt = 0;
    i64 n = s.length();
    rep(i, n){
        if(i + 1 < n && s[i] == 'B' && s[i + 1] == 'C'){
            ans += cnt;
            i += 1;
        }
        else if(s[i] == 'A') ++cnt;
        else{
            cnt = 0;
        }
    }
    cout << ans << endl;
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main(){
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}
