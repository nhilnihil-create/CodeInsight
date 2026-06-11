#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n; double x[10] = {}, ans = 0;
    string u[10] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> u[i];
        if (u[i] == "JPY") ans += x[i];
        else ans += x[i] * 380000;
    }
    printf("%.5f\n", ans);
}