#pragma GCC optimize("Ofast", "unroll-loops")

// #define TEST

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(void){
    string S, T;
    cin >> S >> T;
    vector<char> s_to_t(26, ' ');
    const int sz = S.length();
    for (int i = 0; i < sz; ++i){
        if (s_to_t[S[i] - 'a'] == ' ')
            s_to_t[S[i] - 'a'] = T[i];
        else if (s_to_t[S[i] - 'a'] != T[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    map<char, bool> appered;
    for (int i = 0; i < 26; ++i){
        char from = (char)('a' + i);
        if (s_to_t[i] == ' ') continue;
        if (appered[s_to_t[i]]){
            cout << "No" << endl;
            return 0;
        }
        appered[s_to_t[i]] = true;
    }
    cout << "Yes" << endl;
    return 0;
}