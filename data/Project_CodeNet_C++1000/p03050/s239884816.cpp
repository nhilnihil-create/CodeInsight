#include <iostream>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;
    long long int ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0 && n/i-1 > 0 && n%(n/i-1)==i){
            ans += n/i-1;
        }
    }
    cout << ans << endl;
    return 0;
}