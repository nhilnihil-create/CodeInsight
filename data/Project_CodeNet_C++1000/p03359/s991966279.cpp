#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int a, b;
    cin >> a >> b;

    if (a <= b)
    {
        cout << a << endl;
    }
    else
    {
        cout << a - 1 << endl;
    }

    return (0);
}