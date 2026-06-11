#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    if(s < t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}