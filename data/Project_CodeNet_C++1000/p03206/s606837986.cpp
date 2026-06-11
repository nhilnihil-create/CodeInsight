#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n==25) cout << "Christmas" << "\n";
    else if(n==24) cout << "Christmas Eve" << "\n";
    else if(n==23) cout << "Christmas Eve Eve" << "\n";
    else cout << "Christmas Eve Eve Eve" << "\n";
    return 0;
}