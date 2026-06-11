#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;

int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    int h = (a + b) / 2;
    if(h < c){
        cout << a*x + b*y << endl;
    }else{
        ll ans = 0;
        int MIN = min(x,y);
        ans += c*MIN*2;
        if(x > y){
            if(a > c*2){
                ans += (x-y)*c*2;
                cout << ans << endl;
            }else{
                ans += (x-y)*a;
                cout << ans << endl;
            }
        }
        else if(y > x){
            if(b > c*2){
                ans += (y-x)*c*2;
                cout << ans << endl;
            }else{
                ans += (y-x)*b;
                cout << ans << endl;
            }
        }
        else{
            cout << ans << endl;
        }
    }
}