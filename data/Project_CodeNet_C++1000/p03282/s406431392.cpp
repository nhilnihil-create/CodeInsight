#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    int count = 0;

    for(int i=0; i<S.size(); i++) {
        if(S[i] == '1') count++;
        if(count == K) {
            cout << 1 << endl;
            return 0;
        }
        if(S[i] != '1') {
            cout << S[i] << endl;
            return 0;
        }
    }
}