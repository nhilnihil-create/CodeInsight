#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n; cin >> n;
    string s = "";
    while(1) {
        if(n == 0) break;
        int t = n % (-2);
        if(t == -1) t = 1;
        s += char(48 + t);
        n -= t;
        n /= -2;
    }    
    reverse(s.begin(), s.end());
    if(s.length() == 0) s += '0';

    cout << s;
}