#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> m;
    bool flg = true;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        m[s[i]]++;
        if(m[s[i]] > 1){
            flg = false;
        }
    }
    for(int i = 1; i < n; i++){
        int l = s[i-1].size();
        if(s[i-1][l-1] != s[i][0]){
            flg = false;
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}