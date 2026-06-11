#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,x;
    cin >> a >> b >> x;
    if(a+b>=x && x>=a) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}