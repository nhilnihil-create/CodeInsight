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
    int a,  b;
    cin >> a >> b;
    int ans =0;
    for(int i = a; i <= b; i++) {
        int s1, s2, s3, s4, s5;
        s1 = i % 10;
        s2 = i  / 10 % 10 ;
        s3 =  i/ 10 / 10 % 10;
        s4 =  i/ 10 / 10 / 10 % 10;
        s5 =  i/ 10 / 10 / 10 / 10 % 10;
        if(s1 == s5 && s2 == s4) ans++;
    }
    cout << ans << endl;
}