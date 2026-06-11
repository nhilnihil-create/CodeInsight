#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v(3);
    rep(i, 0, 3) cin >> v[i];
    sort(v.rbegin(), v.rend());
    string a = to_string(v[0]) + to_string(v[1]);
    int sum = stoi(a) + v[2];
    cout << sum << endl;
    return 0;
}