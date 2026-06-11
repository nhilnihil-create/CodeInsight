#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

//while(c){
//    total += c%10;
//    c/=10;
//}

int main() {
    int a,b,c,x;cin >> a >> b >> c >> x;
    int cnt = 0;
    for(int i = 0;i <= a;i++){
        for(int j = 0;j <= b;j++){
            for(int k = 0;k <= c;k++){
                if(i * 500 + j * 100 + k * 50 == x){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}


