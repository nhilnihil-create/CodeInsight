#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    int max_ = 0;
    for (int i=1; i<=100; i++) {
        for (int beki=2; beki<=100; beki++) {
            int num = pow(i, beki);
            if (num > N) {
                break;
            }

            if (num > max_) {
                max_ = num;
            }
        }
    }

    cout << max_ << endl;
    return 0;
}