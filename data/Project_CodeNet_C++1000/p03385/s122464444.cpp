#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    bool a_f = false;
    bool b_f = false;
    bool c_f = false;
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'a') a_f = true;
        if(s[i] == 'b') b_f = true;
        if(s[i] == 'c') c_f = true;
    }
    if(a_f && b_f && c_f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}