#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = b/a;
    if(ans>c) cout << c << endl;
    else cout << ans << endl;
    return 0;
}