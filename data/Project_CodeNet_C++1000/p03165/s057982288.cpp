#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& base) {
    for (T const& i : base) {
        out << i << ' ';
    }
    return out;
}
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int n1 = s.length(), n2 = t.length();
    int DP[n1 + 1][n2 + 1];
    for(int i = 0; i <= n1; ++i) DP[i][0] = 0;
    for(int i = 0; i <= n2; ++i) DP[0][i] = 0;
    for(int i = 1; i <= n1; ++i){
        for(int j = 1; j <= n2; ++j){
            if(s[i-1] == t[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    string ans;
    int i = n1, j = n2;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            --i, --j;
        }
        else{
            if(DP[i][j] == DP[i-1][j]) --i;
            else --j;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}