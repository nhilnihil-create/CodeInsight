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
    int64_t len = S.size();
    int64_t count = 0;
    int64_t b_count = 0;
    for (int64_t i=0; i<len; i++) {
        if (S[i] == 'W') {
            count += b_count;
        } else {
            b_count += 1;
        }
    }

    cout << count << endl;
    return 0;
}