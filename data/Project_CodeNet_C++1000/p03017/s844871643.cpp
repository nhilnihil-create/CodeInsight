#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s; cin >> s;

    s = '#' + s + '#';
    for(int i = a; i + 1<= c; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = b; i + 1 <= d; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(d < c){
        bool flag = false;
        for(int i = b; i <= d; i++){
            if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.'){
                flag = true;
            }
        }
        if(!flag){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
