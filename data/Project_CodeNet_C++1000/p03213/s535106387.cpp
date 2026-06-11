#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> primes;
    map<int, int> primeFact;
    for (int i = 2; i <= N; ++i)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
    }
    for (auto iter = primes.begin(); iter != primes.end(); ++iter)
    {
        primeFact[*iter] = 0;
    }

    for (int i = 2; i <= N; ++i)
    {
        int n = i;
        for (auto iter = primes.begin(); iter != primes.end(); ++iter)
        {
            while(n % *iter == 0)
            {
                primeFact[*iter]++;
                n /= *iter;
            }
            if (n == 1) break;
        }
    }

    map<int, int> count;
    count[74] = 0;
    count[24] = 0;
    count[14] = 0;
    count[4] = 0;
    count[2] = 0;
    for (auto iter = primes.begin(); iter != primes.end(); ++iter)
    {
        if (primeFact[*iter] >= 2) count[2]++;
        if (primeFact[*iter] >= 4) count[4]++;
        if (primeFact[*iter] >= 14) count[14]++;
        if (primeFact[*iter] >= 24) count[24]++;
        if (primeFact[*iter] >= 74) count[74]++;
    }

    int ans = count[74] 
    + count[24] * max(count[2] - 1, 0) 
    + count[14] * max(count[4] - 1, 0) 
    + (count[4] * (count[4] - 1) / 2) * max(count[2] - 2, 0);

    cout << ans << endl;
}
