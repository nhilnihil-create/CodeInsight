#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    if(n%k==0) cout << "0" << "\n";
    else cout << "1" << "\n";

    return 0;
}