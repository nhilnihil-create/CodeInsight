#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Q;
ll A,B;

bool judge(ll mid)
{
    if(mid < A && mid < B)return true;
    if(mid % 2)
    {
        ll mid1,mid2;
        mid1 = mid2 = (mid + 1) / 2;
        if(A <= mid1)mid1++;
        if(B <= mid2)mid2++;
        return mid1 * mid2 < A * B;
    }
    else
    {
        ll mid11,mid12,mid21,mid22;
        mid11 = mid21 = mid / 2;
        mid12 = mid22 = mid11 + 1;
        if(A <= mid11)
        {
            mid11++;
            mid12++;
        }
        else if(A <= mid12)mid12++;
        if(B <= mid21)
        {
            mid21++;
            mid22++;
        }
        else if(B <= mid22)mid22++;
        return (mid21 * mid12 < A * B) && (mid11 * mid22 < A * B);
    }
    return false;
}

int main()
{
    scanf("%d",&Q);

    while(Q--)
    {
        scanf("%lld%lld",&A,&B);
        ll l = 0,r = 2000000000;
        while(r - l > 1)
        {
            ll mid = (l + r) / 2;
            if(judge(mid))l = mid;
            else r = mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}
