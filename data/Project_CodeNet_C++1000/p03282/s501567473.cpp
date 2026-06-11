#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    string S; cin >> S;
    ll K; cin >> K;
    ll index = 0;
    char num = '1';
    rep(i,S.length()) {
        if (S[i] != '1') {
            index = i;
            num = S[i];
            break;
        }
    }
    if (K <= index) {
        cout << 1 << endl;
    }
    else {
        cout << num << endl;
    }



}
