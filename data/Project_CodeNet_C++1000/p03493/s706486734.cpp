#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;
    int ans = 0;
    rep(i, 3) {
        if(s[i] == '1') ans++;
    }

    cout << ans << endl;

    return 0;
}