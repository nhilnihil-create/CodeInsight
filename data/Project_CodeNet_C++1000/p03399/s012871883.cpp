#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
int main(){
    long long a,b,c,d,ans;
    cin >> a >> b >> c >> d;
    if(a < b) {
        ans += a;
    }else{
        ans += b;
    }
    if(c < d) ans +=c;
    else ans += d;
    cout << ans << endl;


    return 0;
}