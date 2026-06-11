#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    map<string, int> blue;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        blue[s]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(blue[s] != 0) blue[s]--;
    }
    int ans = 0;
    for(auto v: blue){
        ans = max(ans, v.second);
    }
    cout << ans << endl;
    return 0;
}