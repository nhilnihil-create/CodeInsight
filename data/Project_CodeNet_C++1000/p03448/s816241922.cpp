#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int x;
    cin >> x;
    int ans = 0;
    rep(i,a+1){
        rep(j,b+1){
            rep(k,c+1){
                if(x == 500 * i + 100 * j + 50 * k) ans++;
            }
        }
    }
    cout << ans << endl;
}