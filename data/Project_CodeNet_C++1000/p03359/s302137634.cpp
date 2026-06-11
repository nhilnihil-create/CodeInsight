#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 1;
    int n = a*1000 + b;
    if(n >= 2002) ans++;
    if(n >= 3003) ans++;
    if(n >= 4004) ans++;
    if(n >= 5005) ans++;
    if(n >= 6006) ans++;
    if(n >= 7007) ans++;
    if(n >= 8008) ans++;
    if(n >= 9009) ans++;
    if(n >= 10010) ans++;
    if(n >= 11011) ans++;
    if(n >= 12012) ans++;

    cout << ans << endl;

}