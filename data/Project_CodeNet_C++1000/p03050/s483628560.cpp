#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}

vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main(){
    ll n; cin >> n;
    vector<ll> num = calc_divisor(n);
    ll ans = 0;
    for(int i=1; i<num.size(); i++){
        if(num[i]!=num[i-1]+1){
            if(n/(num[i]-1)==n%(num[i]-1)) ans+=num[i]-1;
        }
    }

    cout << ans << endl;

}