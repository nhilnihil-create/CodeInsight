#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int t = N;
    int d = 0;
    while (t != 0)
    {
        d += t % 10;
        t /= 10;
    }

    if (N % d == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}