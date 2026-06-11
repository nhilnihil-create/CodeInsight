#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <map>
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n; i>0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORR(i, m, n) for(int i=m; i>=n; i--)
#define INF 1999999999
#define VSORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

#ifdef INPUT
stringstream input(R"(
4 972439611840
)");
#define cin input
#endif

std::map<long long, int> primeFactors(long long n)
{
    std::map<long long, int> m;
    
	for (long long i = 2; i * i <= n; ++i)
    {
		while (n % i == 0)
		{
			++m[i];
			n /= i;
		}
	}
    
	if (n > 1)
        ++m[n];
    
    return m;
} 

int main()
{
    ll n, p, a;
    ll ans = 1;
    cin >> n >> p;

    if (n==1)
        ans = p;
    else if (p == 1)
        ans = 1;
    else
    {
        const auto m = primeFactors(p);
        for (const auto& i:m)
        {
            for (int j=0; j<i.second/n; j++)
            {
                ans *= i.first;
            }
        }
    }

    cout << ans << endl;
    return 0;
}