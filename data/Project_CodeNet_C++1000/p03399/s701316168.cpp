#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans1 = min(a,b);
    int ans2 = min(c,d);

    cout << ans1 + ans2 << endl; 
}