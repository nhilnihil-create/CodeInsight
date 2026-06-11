#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T, A;
    cin >> N >> T >> A;
    int min = 1 << 30, num;
    for (int i = 0; i < N; i++)
    {
        int H;
        cin >> H;
        int d = T * 1000 - H * 6 - A * 1000;
        if (d < 0)
        {
            d = -d;
        }
        if (d < min)
        {
            min = d;
            num = i + 1;
        }
    }
    cout << num << endl;
}