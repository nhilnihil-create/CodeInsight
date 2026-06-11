#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*

 * */

int main() {
    string S; cin >> S;

    string ans;
    if(S <= "2019/04/30"){
        ans = "Heisei";
    }else{
        ans = "TBD";
    }
    cout << ans << endl;
    return 0;
}
