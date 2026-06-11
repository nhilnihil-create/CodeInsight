#include<bits/stdc++.h>
#define rep(i,s,t) for(int i = (int)(s); i <= (int)(t); i++)
#define rev(i,t,s) for(int i = (int)(t); i >= (int)(s); i--)
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
typedef pair<int,int> pii;
deque<pii> que;
const int maxn = 1e5+5;
bool vis[maxn];
int main()
{
    #ifdef LOCAL_FILE
    freopen("in.txt","r",stdin);
    #endif // LOCAL_FILE
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int k;
    cin>>k;
    que.push_front(make_pair(1,1));
    while(!que.empty())
    {
        pii now = que.front();
        que.pop_front();
        if(vis[now.first]) continue;
        vis[now.first] = true;
        if(now.first == 0)
        {
            cout<<now.second<<endl;
            break;
        }
        que.push_front(make_pair(now.first*10%k,now.second));
        que.push_back(make_pair((now.first+1)%k,now.second+1));
    }
    return 0;
}
