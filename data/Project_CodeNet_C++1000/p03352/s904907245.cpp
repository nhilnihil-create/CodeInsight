#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int x;
    cin >> x;

    vector<bool> expo(x + 1);
    expo[1] = true;

    for (int i = 2; i <= x; i++)
    {
        int v = i * i;
        while (v <= x)
        {
            expo[v] = 1;
            v *= i;
        }
    }

    for (int i = x; i >= 1; i--)
    {
        if (expo[i])
        {
            cout << i << endl;
            return (0);
        }
    }
}