#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    for(int i = 0; i < 3; i++){
        if(s[i] == '1') s[i] = '9';
        else s[i] = '1';
    }
    cout << s << endl;


    return 0;
}
