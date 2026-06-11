#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n;
    cin >> n;
    double tot = 0;
    while (n--) {
        string u;
        double x;
        cin >> x >> u;
        if (u == "JPY") tot += x;
        else tot += (x * 380000);
    }
    cout << tot << '\n';
    return 0;
}