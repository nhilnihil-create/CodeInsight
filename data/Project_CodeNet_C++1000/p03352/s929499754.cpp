#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0)return 1;
    else if(n%2 == 1)return EX(x,n-1)*x%mod;
    else return EX(x*x%mod,n/2)%mod;
};

int main(){
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 1; i*i <= x; i++){
        for(int j = 2; j < 10; j++){
            if(ans < EX(i,j) && EX(i,j) <= x) ans = EX(i,j);
            if(EX(i,j) > x) break;
        }
    }    
    cout << ans << endl;
}