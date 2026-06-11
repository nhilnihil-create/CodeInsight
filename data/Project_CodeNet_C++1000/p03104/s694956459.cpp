#include <bits/stdc++.h>
using namespace std;

long long xor_ll(long long x){
    if(x<0) return 0;
    long long y = x%4;
    if(y==1) x = 1;
    else if(y==2) x+=1;
    else if(y==3) x = 0;
    else x = x;
    return x;
}
int main(){
    long long a,b; cin >> a >> b;
    long long ans = xor_ll(b)^xor_ll(a-1);
    cout << ans << endl;
    return 0;
}