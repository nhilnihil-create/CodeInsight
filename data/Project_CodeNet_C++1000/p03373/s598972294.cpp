#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n);i++)

int main(){
    int x, y, a, b, c;
    cin >> a >> b >> c >> x >> y;
    //Max AB+@ or nA+mB
    int p,q,r;
    if(x>y){
        p = 2*c * y + a*(x - y);
    }else{
        p = 2*c * x + b * (y - x);
    }
    r = 2 * c * max(x, y);
    q = a * x + b * y;
    cout << min(min(p,q),r) << endl;
}