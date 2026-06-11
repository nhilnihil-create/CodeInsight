#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    string s;
    cin >> s;
    bool isOK = false;
    if(s == "keyence") isOK = true;
    rep(i, s.length()){
        for(int j = 1; j <= s.length() - i; j++){
            string copied = s;
            copied.erase(i, j);
            if(copied == "keyence") isOK = true;
        }
    }

    if(isOK) cout << "YES" << endl;
    else cout << "NO" << endl;

}