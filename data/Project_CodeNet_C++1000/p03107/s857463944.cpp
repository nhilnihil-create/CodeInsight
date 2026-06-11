#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;



int main() {
    int n; 
    string s;
    cin >> s;

    int cnt0 = 0;
    int cnt1 = 0;
    n = size(s);
    rep(i, n)
    {
        if (s.at(i) == '0') cnt0++;
        if (s.at(i) == '1') cnt1++;
    }
    if (cnt0 > cnt1) cout << cnt1*2 << endl;
    else cout << cnt0*2 << endl;

    return 0;
}
