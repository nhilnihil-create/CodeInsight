#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string calc(int n){
    if(n == 0) return "0";
    if(n == 1) return "1";
    string s;
    int r = abs(n)%2;
    char c = '0'+r;
    s = calc((n-r)/(-2))+c;
    return s;
}

int main() {
    int n;
    cin >> n;

    string ans = calc(n);
    cout << ans << endl;
}
