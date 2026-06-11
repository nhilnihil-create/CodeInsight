#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin>>a>>b>>c;
    cout << min(b/a, c) << "\n";
    return 0;
}