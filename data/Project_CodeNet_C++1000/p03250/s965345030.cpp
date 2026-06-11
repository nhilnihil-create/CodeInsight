#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int ans = -1;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = max<int>({
        10 * a + b + c,
        a + b * 10 + c,
        a + b + c * 10,
    });
    cout << ans << endl;
}