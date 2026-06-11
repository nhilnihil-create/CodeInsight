#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(s[i] == '1') ans++;
    }
    cout << ans << endl;

    return 0;
}