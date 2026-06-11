#include <iostream>
#include <cmath>

#define LL long long

using namespace std;

int main()
{
    LL N, P;
    cin >> N >> P;
    if(1 == N)
    {
        cout << P << endl;
        return 0;
    }

    // double转化为long long有可能会少1，先加回来
    LL ans = pow(P, 1.0/N) + 1;
    for(; ans >= 1; ans--)
    {
        if((P % (LL)pow(ans, N)) == 0)
        {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
