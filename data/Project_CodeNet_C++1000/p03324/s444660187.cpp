#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const int inf =INT_MAX;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
using namespace std;

int main()
{
    ll D, N;
    cin >> D >> N;
    if (N != 100)
    {
        cout << (ll)pow(100, D) * N << endl;
    }
    else
    {
        cout << (ll)pow(100, D) * (N + 1) << endl;
    }
}
