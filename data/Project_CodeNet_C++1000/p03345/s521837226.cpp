#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,k; cin >> a >> b >> c >> k;
    long long ans;
    if(k%2==1) ans=(a-b)*(-1);
    else ans = a-b;
    if(abs(ans)>pow(10,18)) cout << "Unfair" << endl;
    else cout << ans << endl;
}