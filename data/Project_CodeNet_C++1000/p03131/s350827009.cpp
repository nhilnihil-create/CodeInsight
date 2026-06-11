#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t K, A, B;
    cin >> K >> A >> B;
    if (B == 1 || (A + 1 >= B)) {
        cout << K + 1 << endl;
    } else {
        int64_t k = K - A + 1; // 最初に割るまでに必要な回数を引いた後の回数
        int64_t zoukabun = A + (k / 2 * (B - A));
        zoukabun += k % 2;
        cout << zoukabun << endl;
    }

    return 0;
}