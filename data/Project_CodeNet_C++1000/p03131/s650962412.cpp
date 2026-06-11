#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k,a,b; cin >> k >> a >> b;
    ll ans = 1;
    ll dif = b-a;
    if(a+2>=b) ans = 1 + k;
    else if(1+k-2<a) ans = 1 + k;
    else{
        ans = a;
        k = k - (a-1);
        if (k%2!=0){
            k--;
            ans ++;
        }
        for(int i=0; i<k/2; i++){
            ans = ans + dif;
        }
    } 
    cout << ans << endl;
}