#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B;
    cin >> A >> B;
    ll ans = 0;
    if (B - A <= 10){
        for (ll i = A; i <= B; i++){
            ans = ans ^ i;
        }
    }
    else{
        if (A % 4 == 1){
            ans = ans ^ A;
            ans = ans ^ (A + 1);
            ans = ans ^ (A + 2);
        }
        else if (A % 4 == 2){
            ans = ans ^ A;
            ans = ans ^ (A + 1);
        }
        else if (A % 4 == 3){
            ans = ans ^ A;
        }
        
        if (B % 4 == 0){
            ans = ans ^ B;
        }
        else if (B % 4 == 1){
            ans = ans ^ (B - 1);
            ans = ans ^ B;
        }
        else if (B % 4 == 2){
            ans = ans ^ (B - 2);
            ans = ans ^ (B - 1);
            ans = ans ^ B;
        }
    }
    cout << ans << endl;
}
