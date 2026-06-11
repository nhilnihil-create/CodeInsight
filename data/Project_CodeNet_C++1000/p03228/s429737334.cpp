#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    rep(i, 0, k){
        if(i%2 == 0){
            a /= 2;
            b += a;
        }else{
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}