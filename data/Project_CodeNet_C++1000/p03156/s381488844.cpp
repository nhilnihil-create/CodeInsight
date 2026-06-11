#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int N,A,B;
    scanf("%d %d %d", &N, &A, &B);
    int num[3] = {0,0,0};
    for(int i = 0; i < N; ++i) {
        int p;
        scanf("%d", &p);
        if(p <= A) ++num[0];
        else if(p <= B) ++num[1];
        else ++num[2];
    }

    int res = min(num[0], min(num[1], num[2]));
    printf("%d\n", res);
    return 0;
}