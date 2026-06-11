#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll L[100010],R[100010];

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%lld%lld",L + i,R + i);

    for(int i = 0; i < N; i++)R[i] *= -1;

    sort(L,L + N);
    reverse(L,L + N);
    sort(R,R + N);
    reverse(R,R + N);

    ll ans = 0,tmp = 0;
    for(int i = 0; i < N * 2; i++)
    {
        if(i % 2 == 0)tmp += L[i / 2];
        else tmp += R[i / 2];
        ans = max(ans,tmp);
    }

    tmp = 0;
    for(int i = 0; i < N * 2; i++)
    {
        if(i % 2 == 0)tmp += R[i / 2];
        else tmp += L[i / 2];
        ans = max(ans,tmp);
    }

    printf("%lld\n",ans * 2);
    return 0;
}
