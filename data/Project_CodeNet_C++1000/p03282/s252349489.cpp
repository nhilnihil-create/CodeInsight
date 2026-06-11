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
    int64_t K;
    cin >> K;
    bool all_one = true;
    int64_t one_break_index = 0;
    int s_size = S.size();
    for (int i=0; i<s_size; i++) {
        if (S[i] != '1') {
            all_one = false;
            one_break_index = i;
            break;
        }
    }

    if (all_one || one_break_index >= K) {
        cout << 1 << endl;
    } else {
        cout << S[one_break_index] << endl;
    }
    return 0;
}