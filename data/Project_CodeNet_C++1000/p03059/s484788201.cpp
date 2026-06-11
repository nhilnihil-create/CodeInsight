#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,t; cin >> a >> b >> t;
    int mul = 1;
    int ans = 0;
    while(a*mul <= t+0.5){
        ans += b;
        mul++;
    }

    cout << ans << endl;
}