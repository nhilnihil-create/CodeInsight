#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll ans = 0,i = 1,ma = sqrt(N);
    while(i <= ma){
        if(N % i == 0 && N/i > i+1){
            ans += N/i - 1;
        }
        i++;
    }
    cout << ans << endl;
}