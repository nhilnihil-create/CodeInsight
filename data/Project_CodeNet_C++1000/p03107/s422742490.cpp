#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> s;
    n = SZ(s);
    int cnt0 = 0, cnt1 = 0;
    rep(i, n) {
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    cout << min(cnt0, cnt1) * 2 << "\n";
    
}