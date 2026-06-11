#include<bits/stdc++.h>
using namespace std;

int main() {
    string S, T; cin >> S >> T;
    swap(S[0], S[2]);
    cout << ((S == T) ? "YES" : "NO") << endl;
    return 0;
}