#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

map<long long, long long> decomposit_prime(long long n)
{
    map<long long, long long> primes;
    long long a = 2;
    while (n >= a * a)
    {
        if (n % a == 0)
        {
            primes[a]++;
            n /= a;
        }
        else
        {
            a++;
        }
    }

    primes[n]++;
    return primes;
}

int main()
{
    cout.precision(18);

    long long N;
    cin >> N;

    vector<long long> c(101, 0);
    for(long long i = 2; i <= N; i++){
      map<long long, long long> m = decomposit_prime(i);
      for(auto x: m){
        c[x.first] += x.second;
      }
    }

    vector<map<long long, long long>> d(2, map<long long, long long>{});
    for(long long i = 1; i <= c[2] + 1; i++)
      d[0][i] = 1;
    
    for(long long i = 3; i <= N; i++) {
      d[i%2].clear();
      for(long long j = 1; j <= c[i] + 1; j++){
        for(auto x : d[(i-1)%2]) {
          if(x.first * j <= 75)
            d[i%2][x.first * j] += x.second;
        }
      }
    }

    cout << d[N%2][75] << endl;

}
