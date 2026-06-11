#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    bool ok = true;
    map<char,char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ok = false;
        if (ima.count(t)) if (ima[t] != s) ok = false;
        ma[s] = t; ima[t] = s;
    }
    if (ok) puts("Yes");
    else puts("No");
}