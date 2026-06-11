#include <bits/stdc++.h>

#define INF 1e7

using namespace std;

const int maxn = 100005;


int main()
{
    int dist[maxn],k,temp,mul_ten,plus_one,ans;
    deque<int> q;

    scanf("%d",&k);
    for (int i=0;i<maxn;i++) dist[i]=INF;
    dist[1]=0;
    q.push_front(1);

    while (!q.empty())
    {
        temp=q.front();
        q.pop_front();

        mul_ten=(temp*10)%k;
        plus_one=(temp+1)%k;

        if (dist[temp]<dist[mul_ten])
        {
            q.push_front(mul_ten);
            dist[mul_ten]=dist[temp];
        }

        if (dist[temp]+1<dist[plus_one])
        {
            q.push_back(plus_one);
            dist[plus_one]=dist[temp]+1;
        }
    }

    ans=dist[0]+1;
    printf("%d",ans);
    return 0;
}
