#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int len = S.size();
    int min_sa = INT_MAX;
    for (int i=0; i<len-2; i++) {
        string s = S.substr(i,3);
        int num = stoi(s);
        int sa = abs(753 - num);
        if (min_sa > sa) {
            min_sa = sa;
        }
    }

    cout << min_sa << endl;
    return 0;
}