#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin >> S;
    int a = 0; 
    int b = 0; 
    rep(i,S.size()) {
        if (S[i] == 'A' || S[i] == 'T' || S[i] == 'C' || S[i] == 'G') {
            a++;
        }
        else {
            a = 0;
        }
        if (a > b) {
            b = a;
        }
    }
    cout << b << endl;
}