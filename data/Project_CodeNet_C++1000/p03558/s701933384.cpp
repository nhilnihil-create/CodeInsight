#include<bits/stdc++.h>
#define ll long long
#define met(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
const int mod=1e9+7;
const int N=1e6+10;
int a[10010],b[10010],dp[10010][10010];
int v[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,k,m;
    cin>>m;
    deque<pair<int, int> > q;
    met(v,0);
    q.push_back(make_pair(1,1));
    while(!q.empty())
    {
        pair<int, int> n=q.front();
        q.pop_front();
        if(v[n.first])
            continue;
        v[n.first] = 1;
        if(!n.first)
        {
            cout<<n.second<<endl;
            break;
        }
        q.push_front(make_pair(n.first*10 % m, n.second));
        q.push_back(make_pair((n.first+1) % m, n.second+1));
    }
    return 0;
}


