#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int N;
int a[110];

int main()
{
    cin >> N;
    float sum = 0;
    rep(i, N)
    {
        cin >> a[i];
        sum += a[i];
    }
    float avg = sum / float(N);

    float diff = 5000.0;
    int thmfr = 10000;
    int thmidx = 10000;
    rep(i, N)
    {
        float diff2 = abs(a[i] - avg);
        if (diff2 < diff)
        {
            thmfr = a[i];
            thmidx = i;
            diff = diff2;
        }
    }

    cout << thmidx << endl;
}
