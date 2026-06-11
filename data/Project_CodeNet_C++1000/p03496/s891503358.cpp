#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[50];

int main()
{
    int N;

    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> a[i];
    }

    int maxval = *max_element(a, a + N);
    int minval = *min_element(a, a + N);

    if(minval >= 0)
    {
        cout << N - 1 << endl;
        for (int i = 1; i < N;i++)
        {
            cout << i << " " << i + 1 << endl;
        }
    }
    else if(maxval <= 0)
    {
        cout << N - 1 << endl;
        for (int i = N; i > 1; i--)
        {
            cout << i << " " << i - 1 << endl;
        }
    }
    else
    {
        cout << 2 * (N - 1) << endl;
        if(abs(maxval) >= abs(minval))
        {
            int maxi = distance(a, max_element(a, a + N)) + 1;
            for (int i = 1; i <= N; i++)
            {
                if(maxi == i)
                {
                    continue;
                }
                cout << maxi << " " << i << endl;
            }
            for (int i = 1; i < N; i++)
            {
                cout << i << " " << i + 1 << endl;
            }
        }
        else
        {
            int mini = distance(a, min_element(a, a + N)) + 1;
            for (int i = 1; i <= N; i++)
            {
                if (mini == i)
                {
                    continue;
                }
                cout << mini << " " << i << endl;
            }
            for (int i = N; i > 1; i--)
            {
                cout << i << " " << i - 1 << endl;
            }
        }
    }

    return 0;
}