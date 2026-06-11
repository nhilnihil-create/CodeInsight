#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
using namespace std;
const int maxn = 2e5+10;
const int maxm = 4e6+10;
const double eps = 1e-5;
const int mod = 1e9+7;

int dis[maxn];
bool vis[maxn];
deque<int> q;
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif // local
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    dis[1]=1;
    q.push_front(1);
    while(!q.empty()) {
        int tmp=q.front();
        q.pop_front();
        if(vis[tmp]) continue;
        vis[tmp]=true;
        if(tmp==0) break;
        if(!dis[tmp*10%k]||dis[tmp*10%k]>dis[tmp]) {
            dis[tmp*10%k]=dis[tmp];
            q.push_front(tmp*10%k);
        }
        if(!dis[(tmp+1)%k]||dis[(tmp+1)%k]>dis[tmp]+1) {
            dis[(tmp+1)%k]=dis[tmp]+1;
            q.push_back((tmp+1)%k);
        }
    }
    cout<<dis[0]<<endl;
    return 0;
}
