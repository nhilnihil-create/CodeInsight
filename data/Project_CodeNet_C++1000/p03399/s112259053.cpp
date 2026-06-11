#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    a > b ? ans+= b : ans+= a;
    c > d ? ans+= d : ans+= c;

    cout << ans << endl;
}