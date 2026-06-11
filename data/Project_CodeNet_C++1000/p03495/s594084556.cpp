#include <bits/stdc++.h>
#define assem99 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define endll '\n'
#define sz(a) (int)(a).size()
#define RWFile freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
int dx[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dy[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
const int MOD = 1e8, N = 2e6 + 5, oo = 1e9;
const double pi = acos(-1);
using namespace std;

bool prime[N];
vector<int> primes;
int arr[N];
void sieve(int n) {
    memset(prime, 1, sizeof prime);
    for (int p = 2; p * p <= n; p++)
    {
        if(prime[p])
        {
            for(int i = p * p; i <= n; i += p) prime[i] = 0;
        }
    }
    for(int i = 2; i < n; i++) if(prime[i]) primes.push_back(i);
}

map<int, vector<int>> mp;
void getPrimes(int n, int i)
{
    while (n % 2 == 0)
    {
        mp[i].push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            mp[i].push_back(i);
            n /= i;
        }
    }
    if (n > 2) mp[i].push_back(n);
}

int main()
{
    assem99
    int n, k; cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        int a; cin>>a;
        arr[a]++;
    }
    ll ans = 0;
    sort(arr, arr + n, greater<int>());
    for(int i = k; i < N; i++) ans += arr[i];
    cout<<ans;

    return 0;
}