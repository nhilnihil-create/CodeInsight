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
    string t = S;
    int size_ = t.size();
    bool is_keyence = false;
    for (int i=0; i<size_; i++) {
        string f = S.substr(0, i+1);
        for (int j=i+1; j<size_; j++) {
            string e = S.substr(j, size_-j);
            if (f + e == "keyence") {
                is_keyence = true;
                break;
            }
        }
    }

    if (is_keyence) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}