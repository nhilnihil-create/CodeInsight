#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    string s;
    cin >> s;
//    int ix = 0;
//    while((ix = (int)s.find("BC", ix)) >= 0){
//        s.replace(ix, 2, "D");
//    }
//    string sub = "";
    ll ans = 0;
    ll a = 0;
    rep(i, s.length()){
        if(s[i] == 'A') a++;
        if(s[i] == 'C') a = 0;
        if(s[i] == 'B' && i != s.length()-1){
            if(s[i+1] == 'C') {
                ans += a;
                i++;
            }
            else a = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
