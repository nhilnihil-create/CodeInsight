#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    string s, t;
    cin >> s >> t;
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    sort(s.begin(), s.end());
    if (s < t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}