#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((abs(a-b)<=d && abs(b-c)<=d)||abs(c-a)<=d) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}