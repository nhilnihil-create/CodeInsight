#include <bits/stdc++.h>
using namespace std;

int evenColor(string S) {
    int res = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i % 2 != 0 && S.at(i) != '0') {
            S.at(i) = '0'; res++;
        } 
        if (i % 2 == 0 && S.at(i) != '1') {
            S.at(i) = '1'; res++;
        } 
    }
    return res;
}

int oddColor(string S) {
    int res = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i % 2 == 0 && S.at(i) != '0') {
            S.at(i) = '0'; res++;
        }
        if (i % 2 != 0 && S.at(i) != '1') {
            S.at(i) = '1'; res++;
        }
    }
    return res;
}

int main() {
    string S; cin >> S;
    cout << min(evenColor(S), oddColor(S)) << endl;
}