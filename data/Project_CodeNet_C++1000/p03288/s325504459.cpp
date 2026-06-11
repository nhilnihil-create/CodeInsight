#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int R;
    cin >> R;

    if (R < 1200)
    {
        cout << "ABC" << endl;
    }
    else if (R >= 1200 && R < 2800)
    {
        cout << "ARC" << endl;
    }
    else if (R >= 2800)
    {
        cout << "AGC" << endl;
    }
    return (0);
}