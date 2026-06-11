#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    char c;
    cin >> c;
    if (c == 'A') {
        cout << 'T' << endl;
    } else if (c == 'G') {
        cout << 'C' << endl;
    } else if (c == 'T') {
        cout << 'A' << endl;
    } else if (c == 'C') {
        cout << 'G' << endl;
    }
    return 0;
}