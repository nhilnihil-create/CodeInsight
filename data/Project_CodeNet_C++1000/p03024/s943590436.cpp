#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int win = 0;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] == 'o') win++;
    }
    win += 15 - S.size();
    if(win >= 8){
        cout << "YES" << "\n";
    } else{
        cout << "NO" << "\n";
    }
    return 0;
}