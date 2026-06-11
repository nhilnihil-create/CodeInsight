#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main(void) {
    ll n, p;
    ll ans = 1;
    cin>>n>>p;

    if(p==1){
        cout<<1<<endl;
        return 0;
    }else if(n==1){
        cout<<p<<endl;
        return 0;
    }

    map<ll, ll> prime_division;
    /*
    for(ll i=2; p>1; i++) {
        while((p % i) == 0) {
            prime_division[i]++;
            p /= i;
            if(prime_division[i]==n){
                ans*=i;
                prime_division[i]=0;
            }
        }
    }
    */

    for (int i = 1; pow(i, n) <= p; i++) {
        if (p % (ll)pow(i, n) == 0)
            ans = i;
    }

    cout<<ans<<endl;

    return 0;
}
