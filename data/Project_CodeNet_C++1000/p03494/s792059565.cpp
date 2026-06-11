#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool check(int *vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (*vec % 2 != 0)
        {

            return false;
        }
        vec++;
    }
    return true;
}

int main()
{
    int N;
    int count = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    while (check(A, N) == true)

    {
        count++;
        for (int i = 0; i < N; i++)
        {
            if (A[i] % 2 == 0)
            {
                A[i] = A[i] / 2;
            }
        }
    }

    cout << count << endl;
}
