#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N, P;
    cin >> N >> P;
    long long mx = pow(P, 1.0/N);
    long long ans = mx;
    for(int i = mx + 1; i >= 1; i--)
    {
        long long temp = pow(i, N);
        if((P % temp) == 0)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}