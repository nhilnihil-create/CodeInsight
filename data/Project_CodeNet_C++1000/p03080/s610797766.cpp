#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long

signed main() {
    int n;
    string s;
    cin >> n >> s;
    
    int cntR = 0, cntB = 0;
    for(int i = 0 ; i < n; i++){
        if(s[i] == 'R') cntR++;
        if(s[i] == 'B') cntB++;
    }
    if(cntR > cntB) cout << "Yes" << endl;
    else cout << "No" << endl;
}