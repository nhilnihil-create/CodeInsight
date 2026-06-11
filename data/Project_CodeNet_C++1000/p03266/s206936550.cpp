#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans=0;
    ans+=(n/k)*(n/k)*(n/k);
    if(k%2==0){
        ll count;
        count=(n-k/2)/k + 1;
        if(n<k/2) count=0;
        ans += count*count*count;
    }
    cout << ans << endl;
}