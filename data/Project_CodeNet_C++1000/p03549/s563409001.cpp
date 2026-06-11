#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    ll ans;
    n-=m;
    ans=(1900*m+100*n)*(pow(2,m));
    cout << ans << endl;
}