#include<cstdio>
using namespace std;
const int MAX_N = 100;
int N;
int
A[MAX_N];
int D, X;
int main()
{
    scanf("%d", &N);
    scanf("%d%d", &D, &X);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", A + i);
    }
    int ans = X;
    for(int i = 0; i < N; ++i)
    {
        int tmp = (D - 1) / A[i] + 1;
        ans += tmp;
    }
    printf("%d\n", ans);
    return 0;
}