#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string S;
    cin >> S;
    if(S == "keyence") {
        cout << "YES" << endl;
        return 0;
    }
    for(ll i = 0;i < S.size();i++) {
        for(ll j = i;j < S.size();j++) {
            string temp;
            for(ll k = 0;k < S.size();k++) {
                if(k < i || j < k) temp.push_back(S[k]);
            }
            if(temp == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
