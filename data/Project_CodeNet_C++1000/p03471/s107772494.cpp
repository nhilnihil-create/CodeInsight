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
typedef pair<int, int> pair;

int main(){
    int n, y; 
    cin >> n >> y;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int k = n - i - j;
            if (k >= 0 && k <= n) {
                if (i * 10000 + j * 5000 + k * 1000 == y) {
                    cout << i << ' ' << j << ' ' << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}
