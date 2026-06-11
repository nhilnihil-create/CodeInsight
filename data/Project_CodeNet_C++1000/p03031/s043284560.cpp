#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ar array

const int mxN = 20;

int p[mxN],num_lights_on[mxN];
vector<int>adj[mxN];
bool switches[mxN];
int N,M;

int check()
{
    memset(num_lights_on,0,sizeof(num_lights_on));

    for(int i = 0 ; i < M; i++)
    {
        for(auto x : adj[i])
        {
            num_lights_on[i] += switches[x];
        }

        if((num_lights_on[i] % 2) != p[i])
            return 0;
    }

    return 1;
}

void solve()
{
    cin>>N>>M;

    for(int i = 0 ; i < M; i++)
    {
        int K;
        cin>>K;

        for(int j = 0 ; j < K; j++)
        {
            int S;
            cin>>S;
            S--; //zero indexing

            adj[i].pb(S);
        }
    }

    for(int i = 0 ; i < M; i++)
        cin>>p[i];

    int ans = 0;

    for(int i = 0 ; i < pow(2,N); i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            switches[j] = (i >> j) & 1;
        }

        ans += check();
    }

    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}