#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;


int main() {
    string S; cin >> S;
    ll ans = 0;
    for(auto ch : S) if(ch == '2') ans++;
    cout << ans << endl;
}