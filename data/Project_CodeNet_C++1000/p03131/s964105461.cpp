#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll K, A, B;
    cin >> K >> A >> B;
    
    ll coins = 0;
    if( K < A - 1){
        coins = 1 + K;
    } else if(B - A >= 2){
        coins = B + ((K-(A-1))/2-1) * (B-A) + (K-(A-1))%2;
    } else {
        coins = 1 + K;
    }

    cout << coins << endl;

    return 0;
}
