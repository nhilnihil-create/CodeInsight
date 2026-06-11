#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;

using Edge = vector<list<int>>;
Edge edge;
vec used;
bool flag = false;
int T[2]={};

void dfs(int v,int team)
{
    used[v]=team;
    T[team]++;
    for(auto & u : edge[v])
    {
        if(used[u]==-1)
        {
            dfs(u,(team+1)%2);
        }
        else if(team==used[u])
        {
            flag = true;
        }
    }
}


int main()
{
    int N,M;
    cin >> N >> M;
    edge=Edge(N);
    used=vec(N,-1);

    for(int i=0;i<M;++i)
    {
        int A,B;
        cin >> A >> B;
        --A;--B;
        edge[A].emplace_back(B);
        edge[B].emplace_back(A);
    }

    dfs(0,0);

    if(flag)
    {
        cout << 1ll*N*(N-1)/2 - M << endl;
    } else{
        cout << 1ll*T[0]*T[1] - M << endl;
    }

    return 0;
}