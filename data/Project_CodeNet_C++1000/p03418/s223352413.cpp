#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin >> n;
    ll k;cin >> k;
    ll ans = 0;
    if(k == 0){
        ans = n*n;
    }
    else{
        for(int i=k+1;i<=n;i++){
            ans += (i-k)*(n/i)+max((n%i-k+1),(ll)0);
        }
    }
    cout << ans << endl;
}