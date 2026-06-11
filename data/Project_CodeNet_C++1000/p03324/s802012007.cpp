#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    int d,n;
    cin >> d >> n;
    vector<int> ans(99);
    if(d==0){
        if(n == 100) cout << 101 << endl;
        else cout << n << endl;
    }
    else if(d == 1 ){
        if(n != 100){
            rep(i,99) ans.at(i) = 100 * (i+1);
            cout << ans.at(n-1) << endl;
        }
        else cout << 10100;
    }
    else{
        if(n != 100){
            rep(i,99) ans.at(i) = 10000*(i+1);
            cout << ans.at(n-1) << endl;
        }
        else cout << 1010000;
    }

}