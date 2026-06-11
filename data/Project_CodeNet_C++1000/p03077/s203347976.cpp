#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,a,b,c,d,e,ans,x;
    cin >> n >> a >> b >> c >> d >> e;
    ans = 0;
    x = min(a,min(b,min(c,min(d,e))));
    if(n % x == 0){
        ans += n/x;
    }else if(n <= x){
        cout << 5 << endl;
        return 0;
    }else{
        ans += n/x+1;
    }
    ans += 4;
    cout << ans << endl;
    return 0;
}