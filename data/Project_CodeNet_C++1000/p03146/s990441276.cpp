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

ll a[1000010];

int main(){
    int s;
    cin >> s;

    for (int i = 0; i < 1000000; i++) {
        a[i] = s;
        if (s%2 == 0) {
            s = s / 2;
        }
        else {
            s = s * 3 + 1;
        }
    }
    for (ll i = 0; i < 1000000; i++) { 
        for (ll j = i + 1; j < 1000000; j++) {
            if (a[i] == a[j]) {
                cout << j + 1 << endl;
                return 0;
            }
        }
    }
}