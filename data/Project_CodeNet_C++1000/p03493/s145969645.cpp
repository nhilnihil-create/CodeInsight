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
    int s ;
    cin >> s;
    int s1, s2, s3;
    s1 = s / 100 % 10;
    s2 = s / 10 % 10 ;
    s3 = s % 10;
    cout << s1 + s2 + s3 << endl;
}