#include <algorithm>
#include <iostream>
#include <string>

#include <vector>

#include <functional>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    int *m;
    int sum = 0;
    int tmp = 0;

    int ans, start, end;

    m = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }

    int min = m[0];
    for (int i = 1; i < N; i++)
    {
        if (min > m[i])
        {
            min = m[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        sum = sum + m[i];
    }

    X -= sum;

    tmp = X / min;

    cout << tmp + N << endl;
}
