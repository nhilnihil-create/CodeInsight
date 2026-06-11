#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++){
        if(s[i] == '9') s[i] = '1';
        else if(s[i] == '1') s[i] = '9';
    }
    cout << s << endl;
}
