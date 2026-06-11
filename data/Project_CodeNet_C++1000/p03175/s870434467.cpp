#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=100005;
vector<int> v[N];

array<ll,2> dfs(int a,int p=-1)
{
    array<ll,2> now={1,1};
    for(int to:v[a])
    {
        if(to==p) continue;
        array<ll,2> nxt=dfs(to,a);
        now[0]=(now[0]*(nxt[0]+nxt[1]))%mod;
        now[1]=(now[1]*nxt[0])%mod;
    }
    return now;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    array<ll,2> a=dfs(1);
    cout << (a[0]+a[1])%mod << "\n";
    return 0;
}
