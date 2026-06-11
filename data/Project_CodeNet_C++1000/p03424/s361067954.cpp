#include<bits/stdc++.h>
using namespace std;
// マクロ
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
// 型エイリアス
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;

int main() {
    int n;
    cin >> n;
    bool ans = false;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "Y") {
            ans = true;
            break;
        }
    }
    if(ans) cout << "Four" << endl;
    else cout << "Three" << endl;
}
