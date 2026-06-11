#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    for (int nnn = 0; nnn < N; nnn++)
    {
        long long a, b;
        cin >> a >> b;
        if (a<b) swap(a, b);

        long long res = 2 * (b - 1);
        
        if (a != b)
        {
            long long sqr = sqrt(a * b);
            if (sqr * sqr == a * b)
            {
                res += (sqr - b) * 2 - 1;;
            }
            else
            {
                res += (sqr - b) * 2 + 1;
                if (sqr * (sqr+1) >= a * b) res--;
            }
        }
        cout << res << endl;
    }
    return 0;
}