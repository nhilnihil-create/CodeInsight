#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;   cin >> n;
    ll ans=1e+5;
    for(int i=1; i<=n/2; i++){
        ll b = n-i, a=i, sum=0;

        while(0<b){
            sum += b%10;
            b /= 10;
        }
        while(0<a){
            sum += a%10;
            a /= 10;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}