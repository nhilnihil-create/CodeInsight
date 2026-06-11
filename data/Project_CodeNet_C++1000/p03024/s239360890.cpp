#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    rep(i, s.size()) if(s[i] == 'o') cnt++;
    
    if(8-cnt <= 15-s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}