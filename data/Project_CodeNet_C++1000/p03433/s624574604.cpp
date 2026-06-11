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
    int n, a;
    cin >> n >> a;
    int hasu = n % 500;
    if(hasu <= a) {
        cout <<"Yes" << endl;
    }
    else cout << "No" << endl;
}