#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,ans = 0,fav;
    cin >> n;
    for(long long i = 1;i * i <= n;i++){
        if((n - i) % i == 0){
            fav = (n - i) / i;
            if(fav != 0 &&(n / fav) == (n % fav))ans += fav;
        }
    }
    cout << ans << endl;
}
