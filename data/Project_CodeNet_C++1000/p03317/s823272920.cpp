#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int N, K;
    cin >> N >> K;
    int sum = 0;
    int A[N];
    int min = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (min > A[i])
            min = A[i];
    }
    int i = 0;
    int count = 0;
    while (i < N)
    {
        for (int j = i; j < K + i; j++)
        {   
            if (j > N )break;
            if (A[j] != min)
            {
                count++;
            }
        }
        if (count == K)
        {
            i--;
            sum++;
        }
        else
            sum++;
        //cout << "count = " << count << endl;

        count = 0;

        i += K;
        //cout << "i = " << i << endl;
    }

    /*if (N == K)
    {
        cout << N / K;
        return 0;
    }
    int p = N / K;
    int sum = p + p;
   */
    cout << sum;

    return 0;
}
