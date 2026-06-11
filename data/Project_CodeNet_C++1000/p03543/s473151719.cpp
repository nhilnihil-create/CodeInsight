#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if((s[0]==s[1] && s[1]==s[2]) || (s[1]==s[2] && s[2]==s[3])) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}