#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    vector<bool> isprime(100010, true);
    vll count(100010, 0);

    isprime[0] = false;
    isprime[1] = false;

    for (int i = 2; i < 100010; i++){
        count[i] = count[i-1];
        if (isprime[i]) {
            if (i != 2 && isprime[(i+1)/2]){
                count[i]++;
            }
            for (int j = 2*i; j < 100010; j += i){
                isprime[j] = false;
            }
        }
    }

    ll Q;
    ll l, r;
    cin >> Q;
    int i;
    rep(i, Q){
        cin >> l >> r;
        cout << count[r] - count[l-1] << '\n';
    }


    return 0;
}