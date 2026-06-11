#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;
#define ll long long
 
int main(void){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = k; i <= n; i++){
        if(i > 0)
        ans+=(n-i);
    }
    for(ll i = k+1; i <= n; i++){
        ans+=(n/i-1)*(i-k);
        if(n%i >= k)
            ans+=(n%i-k+1);
    }
    cout << ans << endl;
    return 0;
}