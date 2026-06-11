#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char b;
    cin >> b;
    if(b=='A') cout << "T" << "\n";
    else if(b=='T') cout << "A" << "\n";
    else if(b=='G') cout << "C" << "\n";
    else cout << "G" << "\n";
    return 0;
}