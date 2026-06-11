#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    string S;
    cin >> S;
    map<char, int>d;
    int s_size = S.size();
    for (int i=0; i<s_size; i++) {
        d[S[i]] = 1;
    }

    char s = S[s_size-1];
    if (S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
    } else if (s_size < 26) {
        char new_moji = '-';
        for (char moji='a'; moji<='z'; moji++) {
            if (d.count(moji) == 0) {
                new_moji = moji;
                break;
            }
        }

        cout << S << new_moji << endl;
    } else {
        int i=25;
        char ikemoji = '-';
        while (i >= 0) {
            for ( char moji=++S[i]; moji<='z'; moji++) {
                bool ikeru = true;
                for (int j=0; j<i; j++) {
                    if (moji == S[j]) {
                        ikeru = false;
                    }
                }

                if (ikeru) {
                    ikemoji = moji;
                    break;
                }
            }

            if (ikemoji != '-') {
                break;
            }

            i--;
        }

        cout << S.substr(0, i) << ikemoji << endl;
    }
    return 0;
}