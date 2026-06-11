#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B,K;
    cin >> A >> B >> K;
    for (ll i = 1; i <= K; i++){
        if (i % 2 == 1){
            if (A % 2 == 1) A--;
            B += A / 2;
            A /= 2;
        }
        else{
            if (B % 2 == 1) B--;
            A += B / 2;
            B /= 2;
        }
    }
    cout << A << " " << B << endl;
}
