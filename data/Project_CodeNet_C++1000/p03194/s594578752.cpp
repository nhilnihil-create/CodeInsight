// Created by sz
#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;




int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N,P;
    cin>>N>>P;
    if(N==1){
        cout<<P<<endl;
        return 0;
    }
    

    ll p = P;
    ll divisor = 2;
    ll ans = 1;
    while(p&&pow(divisor,N)<=p){
        while (p%divisor != 0) {
            divisor ++;
        }
        int cnt = 0;
        while (p%divisor == 0) {
            p= p/divisor;
            ++cnt;
        }
        ans *= pow(divisor, cnt/N);
    }
    cout<<ans<<endl;
    return 0;
}

