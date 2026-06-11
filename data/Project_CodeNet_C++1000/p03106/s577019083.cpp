#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            v.push_back(i);
        }
    }
    int n = v.size();
    cout << v[n - k] << '\n'; 
}