#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int A, B;
    cin >> A >> B;
    int sum = 0;
    if (A > B) {
        sum = A;
        A--;
    } else {
        sum = B;
        B--;
    }

    sum += max(A, B);
    cout << sum << endl;
    return 0;
}