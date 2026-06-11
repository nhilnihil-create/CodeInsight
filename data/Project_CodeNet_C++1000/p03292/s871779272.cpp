#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    cout << max({a,b,c})-min({a,b,c}) << "\n";

    return 0;
}