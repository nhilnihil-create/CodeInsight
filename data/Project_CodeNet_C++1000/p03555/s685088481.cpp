#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string s,t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    if(s == t) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}