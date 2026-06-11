#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll num[2];
    cin >> num[0] >>num[1];
    if(num[0] != 0){
        num[0]--;
    }
    ll sum[2] ={};
    for(int i=0;i<2;i++){
        if(((num[i]%4)/2) ^ (num[i]%2)){
            sum[i] =1;
        }
    }
    // cerr <<"A=" << sum[0] << "B=" << sum[1] << endl;

    for(int i=0;i<2;i++)for(ll j=1ll;j<=50;j++){
        if(!(num[i]&1)){
            sum[i] |= (num[i] &(1<<j));
        }
    }
    //  cerr <<"sumA=" << sum[0] << "sumB=" << sum[1] << endl;
    cout << (sum[0]^sum[1]) << endl;

    

    return 0;
}