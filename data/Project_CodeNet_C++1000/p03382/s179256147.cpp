#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[100005];
void Read()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1);
}

void Solve()
{
    int Max = 0, PMax = 0;
    for(int i = 1; i < N; i++)
    {
        bool rev = 0;
        if(A[i] > A[N] - A[i])
            A[i] = A[N] - A[i], rev = 1;
        if(Max < A[i])
        {
            Max = A[i];
            if(rev == 1)
                A[i] = A[N] - A[i];
            PMax = A[i];
        }
    }
    cout << A[N] << " " << PMax << "\n";
}
int main()
{
    Read();
    Solve();
    return 0;
}
