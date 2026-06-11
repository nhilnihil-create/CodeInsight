#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string S;
    cin >> S;

    vector<bool>al(26, false);
    for (char s : S) al[s-'a'] = true;

    if (S.size() == 26) {
        int i = S.size()-1;
        while (S[i-1] > S[i]) {
            if (i == 1) {
                cout << -1 << endl;
                return 0;
            }
            al[S[i]-'a'] = false;
            i--;
        }
        al[S[i]-'a'] = false;
        while (al[S[i-1]-'a']) S[i-1]++;
        S.erase(i);
        cout << S << endl;
        return 0;
    }
    int i = 0;
    while (al[i]) i++;
    S += alphabet[i];
    cout << S << endl;
}
