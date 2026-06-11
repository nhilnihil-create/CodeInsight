#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;

    int ans = INF;
    for(int i = 0; i < (int)s.size()-2; i++){
        int x = stoi(s.substr(i, 3));
        ans = min(ans, abs(x - 753));
    }
    cout << ans << endl;
    return 0;
}