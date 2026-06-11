#include<bits/stdc++.h>
using namespace std;

int N;
int A[100010];

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",A + i);

    sort(A,A + N);
    printf("%d ",A[N - 1]);

    int dif = 1001001001;
    int id = 0;
    for(int i = 0; i < N - 1; i++)
    {
        if(abs(A[N - 1] - A[i] * 2) < dif)
        {
            dif = abs(A[N - 1] - A[i] * 2);
            id = i;
        }
    }
    printf("%d\n",A[id]);
    return 0;
}
