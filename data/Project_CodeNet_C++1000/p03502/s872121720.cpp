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
    int f = 0, x = n;
    while(n != 0) {
        f += n % 10;
        n /= 10;
    }
    if(x % f == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}