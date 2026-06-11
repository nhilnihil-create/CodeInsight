#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int k, n;
    cin >> k >> n;

    vector<pair<long long int, long long int>> prime_power;
    for (long long int p=2; p*p<=n; p++) {
        if(n % p != 0) continue;// break and proceed to p+1

        int power = 0;
        while(n % p == 0){
            power += 1;
            n /= p;
        }
        prime_power.push_back(make_pair(power, p));
    }

    // n has been divided by all primes (with power) smaller than sqrt(n)
    if(n != 1) prime_power.push_back(make_pair(1, n));

    sort(prime_power.begin(),prime_power.end());
    long long int ans = 1;
    for(auto pp : prime_power){
        int times = pp.first;
        while(times >= k){
            ans *= pp.second;
            times -= k;
        }
    }
    cout << ans << endl;
    return 0;
}