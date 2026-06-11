#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int digit = s.size();
    int k = s.front() - '0';

    // n 以下の整数の特徴
    // 1. digit 桁目は k 以下
    // 2. それ以外の桁は 9 以下
    // よって答えの上限は k + 9(digit - 1)
    //
    // 答えの元となる整数は次の2通り
    // a. k999...999
    // b. (k-1)999...999

    bool is_a = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '9') {
            is_a = false;
            break;
        }
    }

    int ans;
    if (is_a)
        ans = k + 9 * (digit - 1);
    else
        ans = k + 9 * (digit - 1) - 1;

    printf("%d\n", ans);
}