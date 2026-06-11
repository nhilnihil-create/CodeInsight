#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    string strs; 
    cin >> strs; 
    for (auto &s: strs) {
        if (s == '1') cout << '9';
        else if (s == '9') cout << '1'; 
        else cout << s; 
    }
    cout << endl; 
    return 0; 
}