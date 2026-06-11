#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s, t;
    cin >> s >> t;

    if(s == t){
        cout << "Yes" << endl;
        return 0;
    }
    bool ok = false;
    for(int i = 0; i < (int)s.size(); i++){
        string chg;
        chg = s[s.size()-1] + s.substr(0, (int)s.size()-1);
        if(chg == t) ok = true;
        s = chg;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}