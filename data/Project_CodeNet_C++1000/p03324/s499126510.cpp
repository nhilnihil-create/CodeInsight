#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll D, N;
    cin >> D >> N;
    if (N != 100)
    {
        cout << (ll)pow(100, D) * N << endl;
    }
    else
    {
        cout << (ll)pow(100, D) * (N + 1) << endl;
    }
}
