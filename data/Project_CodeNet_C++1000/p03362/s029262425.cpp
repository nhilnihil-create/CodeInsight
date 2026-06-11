#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    vector<ll> vec;
    for(ll i=1;i<=55555;i++){
        if(is_prime(i)&&i%5==1) vec.push_back(i);
    }
    for(ll i=0;i<n;i++){
        cout << vec[i];
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
}
