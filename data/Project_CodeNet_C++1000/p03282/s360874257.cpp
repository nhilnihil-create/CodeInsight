#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    ll k; cin >> k;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '1' && i == k - 1){
            cout << 1 << endl;
            return 0;
        }
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }

    return 0;
}
