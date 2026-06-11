#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main() {
    string s;
    long long k;
    cin >> s >> k;
    rep(i,k){
        if(s.at(i) != '1'){
            cout << s.at(i) << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}