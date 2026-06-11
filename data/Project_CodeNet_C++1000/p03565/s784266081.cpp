#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string S, T;
    cin >> S >> T;
    int ind = -1;
    for (int i = 0; i < S.size() - T.size() + 1; i ++) {
        int f = 1;
        for (int j = 0; j < T.size(); j ++) {
            if (S[i + j] !='?' && S[i + j] != T[j]) {
                f = 0;
                break;
            }
        }
        if (f) {
            ind = i;
        }
    }
    if (ind == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    } else {
        for (int j = 0; j < T.size(); j ++) {
            S[ind + j] = T[j];
        }
    }
    for (int i = 0; i < S.size(); i ++) {
        if (S[i] == '?') {
            cout << "a";
        } else {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}