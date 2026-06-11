#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    char a;
    int idx = 0;
    rep(i,s.size()) if(s[i] != '1'){
        a = s[i];
        idx = i;
        break;
    }
    if(idx >= k) cout << 1 << endl;
    else cout << a << endl;
}