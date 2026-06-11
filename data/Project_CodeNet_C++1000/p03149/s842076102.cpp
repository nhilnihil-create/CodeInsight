#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        S += s;
    }
    sort(S.begin(), S.end());
    cout << ((S == "1479") ? "YES" : "NO") << endl;
    return 0;
}