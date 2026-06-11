#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
//using u64 = ::std::int_least64_t;
using u64 = int;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

const int MAXN = 100000;
int primes[MAXN], cnt;
map<int, int> factors;
void sieve(int *primes, int n, int &cnt)
{
    cnt = 0;
    memset(primes, 1, n * sizeof(int));

    for (int i = 2; i < n; i++)
    {
        if (primes[i]) primes[cnt++] = i;
        for (int j = 0; j < cnt && i * primes[j] < n; j++)
        {
            primes[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
}


int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    
    sieve(primes, MAXN, cnt);
    
    int sprimes[MAXN], cnt1 = 0;
    
    for (int i = 0; i < MAXN; i++) {
        sprimes[i] = Inf;
    }
    
    
    for (int i = 1; i < cnt; i++) {
        int target = (primes[i] + 1) / 2;
        if(binary_search(primes, primes + cnt, target)) sprimes[cnt1++] = primes[i];
    }
    
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int left = upper_bound(sprimes, sprimes + cnt1, l - 1) - sprimes - 1;
        int right = upper_bound(sprimes, sprimes + cnt1, r) - sprimes - 1;
        cout << right - left << endl;
    }
    
    return 0;
}
