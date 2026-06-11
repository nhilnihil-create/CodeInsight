#include <iostream>
using namespace std;
long long gcd(long long x, long long y){
    if(x%y==0) return y;
    else return gcd(y,x%y);
}
int main(void){
    long long n,i,a[100000];
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    long long ans = a[0];
    for(i=1;i<n;i++){
        ans = min(ans,gcd(ans,a[i]));
    }
    cout << ans;
}