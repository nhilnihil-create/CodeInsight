#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    string s;
    ll k;
    cin >> s >> k;
    int i = 0;
    bool is_1 = true;
    rep(j, k){
        if(s[j] != '1'){
            is_1 = false;
            break;
        }
    }
    while(s[i] == '1'){
        i++;
    }
    if(is_1) cout << 1 << endl;
    else cout << s[i] << endl;
}