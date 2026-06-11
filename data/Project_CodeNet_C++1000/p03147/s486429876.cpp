#include <iostream>
using namespace std;

int main(void)
{
    int count, a[100], i, N;

    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    count = a[0];
    for (i = 0; i < N - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            count = count + a[i + 1] - a[i];
        }
    }
    cout << count << endl;
    return 0;
}