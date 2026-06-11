#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    string s; cin >> s;
    int L = s.size(), cnt = 0;
    int left = 0, right = L - 1;
    bool flag = true;

    while (left < right && flag) {
        if (s[left] == s[right]) left++, right--;
        else if (s[left] == 'x') left++, cnt++;
        else if (s[right] == 'x') right--, cnt++;
        else flag = false;
    }
    if (flag) cout << cnt << endl;
    else cout << -1 << endl;


}

