#include<bits/stdc++.h>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

typedef pair<int,int> pii;

int N;
int A[300010];
pii dp[300010];

int main()
{
    cin >> N;
    int K = (1 << N);
    for(int i = 0; i < K; i++)cin >> A[i];
    A[K] = -1;

    for(int i = 1; i < K; i++)dp[i] = mk(K, K);

    for(int i = 1; i < K; i++)
    {
        int cnt = 0;
        for(int j = 0; j < N; j++)if(i & (1 << j))cnt++;
        if(cnt == 1)
        {
            int idx = 0;
            if(A[0] > A[i])idx = 0;
            else idx = i;
            dp[i] = mk(idx,i - idx);
        }
        else
        {
            for(int j = 0; j < N; j++)if(i & (1 << j))
            {
                pii tmp = dp[i ^ (1 << j)];
                vector<pii> v;
                v.push_back(mk(A[dp[i].fi],dp[i].fi));
                v.push_back(mk(A[dp[i].se],dp[i].se));
                v.push_back(mk(A[tmp.fi],tmp.fi));
                v.push_back(mk(A[tmp.se],tmp.se));
                v.push_back(mk(A[i],i));
                sort(v.begin(),v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
                reverse(v.begin(), v.end());
                dp[i] = mk(v[0].se, v[1].se);
            }
        }
    }

    int MAX = 0;
    for(int i = 1; i < K; i++)
    {
        MAX = max(MAX,A[dp[i].fi] + A[dp[i].se]);
        printf("%d\n",MAX);
    }

    return 0;
}
