#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    int n; 
    cin >> n; 
    int odd, even; 
    odd = n / 2; 
    even = n / 2; 
    if (n % 2 == 1) ++odd; 
    cout << odd * even << endl; 
    return 0; 
}