#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = k; i <= (int)(n); i++)
using ll = long long;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int cnt = 0;
    rep(ai, 0, a){
        rep(bi, 0, b){
            rep(ci, 0, c){
            if (ai * 500 + bi * 100 + ci * 50 == x) cnt ++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}