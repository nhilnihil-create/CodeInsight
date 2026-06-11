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
    int s_size = S.size();
    int one_count = 0;
    int zero_count = 0;
    for (int i=0; i<s_size; i++) {
        if (S[i] == '0') {
            zero_count += 1;
        } else {
            one_count += 1;
        }
    }

    cout << 2 * min(one_count, zero_count) << endl;
    return 0;
}