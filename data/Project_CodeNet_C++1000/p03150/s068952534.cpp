#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string S;
    cin >> S;
    string t = "keyence";
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (S[i] == t[i]) {
            cnt++;
        }
    }
    if (cnt == 7) {
        cout <<  "YES" << endl;
        return 0;
    }
    cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (S[S.size()-1-i] == t[7-1-i]) {
            cnt++;
        }
    }
    if (cnt == 7) {
        cout << "YES" << endl;
        return 0;
    }
    string t1 = "";
    int i = 0;
    while (true) {
        if (S[i] == t[i]) {
            t1 += S[i];
            i++;
        } else {
            break;
        }
    }
    string t2 = "";
    for (int j = i; j < 7; j++) {
        if (S[S.size()-7+j] == t[j]) {
            t2 += t[j];
        }
    }
    if (t1+t2 == "keyence") {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
