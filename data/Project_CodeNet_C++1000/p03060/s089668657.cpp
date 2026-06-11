#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n;
    cin >> n;
    int v[n],c[n];
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];
    int ans = 0;
    rep(i,n){
        if(v[i] - c[i] >= 0){
            ans += v[i] - c[i];
        }
    }
    cout << ans << endl;
}