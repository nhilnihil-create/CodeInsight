#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[N+1];
    for(int i = 1; i <= N; i++) cin >> A[i];

    int res = 0;

    for(int i = 1; i < N; i++)
    {
        if(A[i] == A[i+1])
        {
            A[i+1] = -1;
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}