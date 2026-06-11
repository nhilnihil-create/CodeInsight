#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

const int MAX_N = 110;
char A[MAX_N], B[MAX_N], C[MAX_N];
int num[MAX_N][30];

int main()
{
    int N;
    scanf("%d", &N);
    scanf("%s %s %s", A, B, C);
    for(int i = 0; i < N; ++i) ++num[i][A[i]-'a'], ++num[i][B[i]-'a'], ++num[i][C[i]-'a'];

    int res = 0;
    for(int i = 0; i < N; ++i) {
        int tmp = 3;
        for(int j = 0; j < 26; ++j) tmp = min(tmp, 3 - num[i][j]);
        res += tmp;
    }
    printf("%d\n", res);
    return 0;
}