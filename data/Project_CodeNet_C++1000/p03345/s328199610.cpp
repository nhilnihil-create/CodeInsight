#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    if(A == B) {
        cout << 0 << endl;
    } else {
        //cout << (A - B)*(1 - 2*(K%2)) << endl;
        cout << (A - B)*(ll)pow(-1,K%2) << endl;
    }
    
    return 0;
}