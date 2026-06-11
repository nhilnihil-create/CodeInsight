#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<algorithm>
#define ll long long
#define rep(i,a,b) for(int i = a;i < b;i++)
#define INF 1e17
#define N 200004

using namespace std;

ll n;
unsigned ll X,x[N],pre[N];
unsigned ll ans;

unsigned ll get_sum(int i,int j)
{
    if(i < 1)
        return pre[j];

    return pre[j] - pre[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> X;

    rep(i,1,n+1)
    {
        cin >> x[i];

        if(i == 1)
            pre[i] = x[i];
        else
            pre[i] = pre[i-1] + x[i];
    }

    ans = INF;

    for(ll reps = 1;reps <= n;reps++)
    {
        unsigned ll cur = 5*get_sum(max((ll)1,n-2*reps+1),n) + reps*X;
        unsigned ll mult = 7;

        for(int j = n-2*reps;j >= 1;j -= reps)
        {
            cur = cur + mult*get_sum(max((ll)1,j-reps+1),j);
            mult += 2;
        }

        ans = min(ans,cur);
    }

    ans += X*n;

    cout << ans;

    return 0;
}

