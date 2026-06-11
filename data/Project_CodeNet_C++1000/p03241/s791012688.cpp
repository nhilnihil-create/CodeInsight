#include <iostream>
using namespace std;
int main()
{
    long long n, m, ans = 0;
    cin >> n >> m;
    for(long long i = 1; i * i <= m; i++)
    {
        if(m % i == 0)
        {
            if(m >= n * i)
            {
                ans = max(ans, i);
            }
            if(m >= n * (m / i))
            {
                ans = max(ans, m / i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}