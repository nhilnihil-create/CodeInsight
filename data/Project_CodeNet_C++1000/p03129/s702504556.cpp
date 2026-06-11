#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    if(2*K - 1 <= N) printf("YES\n");
    else printf("NO\n");
    return 0;
}