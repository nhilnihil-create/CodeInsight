#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    int min = *min_element(A.begin(), A.end());
    int max = *max_element(A.begin(), A.end());
    int a = 0;
    while (min != max)
    {
        for (int i = 0; i < N; i++)
        {
            if (A.at(i) == min)
            {
                continue;
            }

            a = A.at(i) % min;
            A.at(i) = a;
            if (a != 0 && a < min)
            {
                min = a;
            }
        }
        max = *max_element(A.begin(), A.end());
    }

    cout << min << endl;

    return 0;
}