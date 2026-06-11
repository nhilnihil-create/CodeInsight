#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


bool prime(ll n){
    if(n == 2) return true;
    if(n == 1 || n % 2 == 0 ) return false;

    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0) return false;
    }

    return true;

}

int main(){
    ll N;
    vector<bool> isPrime(100001,false);
    vector<ll> prob(100001,0);
    for(int i = 1; i < 100001; i++){
        isPrime[i] = prime(i);
    }

    for(int i = 1; i < 100000; i++){
        if(isPrime[((i + 1) + 1) / 2] && isPrime[i + 1]) prob[i + 1] = prob[i] + 1;
        else prob[i + 1] = prob[i];
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        ll begin, end, ans = 0;
        cin >> begin >> end;

        cout << prob[end] - prob[begin - 1] << endl;
    }
}

