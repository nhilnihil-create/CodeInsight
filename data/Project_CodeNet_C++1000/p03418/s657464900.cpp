#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ll n, k;
    cin >> n >> k;

    ll sum = 0;
    if(k==0){
        sum = n*n;
        cout << sum << endl;
        return 0; 
    }

    for(ll i=1; i<n+1; i++){
        ll tmp = n/i;
        if(i>k){
            sum += tmp*(i-k);
        }

        if(n%i==0) continue;
        else if(n%i>=k){
            sum += n%i-k+1; 
        }
    }

    cout << sum << endl;
} 