#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    cout << (a%b == 0 ? 0 : 1) << "\n";
    return 0; 
}