#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int num[3] = { 0 };
    for (char c : S) {
        num[c - 'a']++;
    }
    int max_num = INT_MIN, min_num = INT_MAX;
    for (int i = 0; i < 3; i++) {
        max_num = max(max_num, num[i]);
        min_num = min(min_num, num[i]);
    }
    if (max_num - min_num >= 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
