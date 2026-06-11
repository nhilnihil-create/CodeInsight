#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x = 0;
    cin >> n;
    while(n - 4*x >= 0 && (n-4*x)%7 != 0) {
        x++;
    }
    if((n-4*x)%7 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0; 
}