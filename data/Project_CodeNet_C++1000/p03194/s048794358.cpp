#include <bits/stdc++.h>
#define ll long long int
using namespace std;
unsigned ll maxGCD(unsigned ll N, unsigned ll P)
{

    unsigned ll ans = 1;
    unordered_map<unsigned ll, unsigned ll> prime_factors;
    for (unsigned ll i = 2; i * i <= P; i++) {

        while (P % i == 0) {

            prime_factors[i]++;

            P /= i;
        }
    }

    if (P != 1)
        prime_factors[P]++;
    for (auto v : prime_factors)
        ans *= pow(v.first, v.second / N);

    return ans;
}
int main()
{
    unsigned ll N,P;
    cin>>N>>P;

    cout << maxGCD(N, P)<<'\n';

    return 0;
}
