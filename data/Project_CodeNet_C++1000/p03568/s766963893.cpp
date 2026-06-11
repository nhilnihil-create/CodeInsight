#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    int64_t kisuupattern = 1;
    int64_t zenpattern = 1;
    for (int64_t i=0; i<N; i++) {
        zenpattern *= 3;
        int64_t num;
        cin >> num;
        if (num % 2 == 0) {
            kisuupattern *= 2;
        } else {
            kisuupattern *= 1;
        }
    }

    cout << zenpattern - kisuupattern << endl;
    return 0;
}