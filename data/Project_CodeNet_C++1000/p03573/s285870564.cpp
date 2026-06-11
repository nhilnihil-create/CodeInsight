#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B)
    {
        cout << C << endl;
    }
    else if (B == C)
    {
        cout << A << endl;
    }
    else
    {
        cout << B << endl;
    }

    return (0);
}