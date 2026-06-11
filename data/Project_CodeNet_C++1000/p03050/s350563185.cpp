#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    
    ll t = 1;
    ll ans = 0;
    while(t*t<N){
       if(N%t==0){
           ll p = (N/t) -1;
           if(N/p == N%p){
               ans += ((N/t)-1);
           }      
        }
        ++t;
    }
    cout << ans << endl;
    return 0;
}