#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    if(s == "keyence") {
        cout << "YES" << endl;
        return 0;
    }

    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string tmp = "";
            for(int k = 0; k < i; k++){
                tmp += s[k];
            }
            for(int k = j; k < n; k++){
                tmp += s[k];
            }
            if(tmp == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;


    return 0;
}
