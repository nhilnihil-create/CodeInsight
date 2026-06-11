#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);
const int MAXN = 1e5+5;
vector<P> v[MAXN];
int vis[MAXN];
int color[MAXN];
int dis[MAXN];
void bfs(int st)
{
    dis[st] =0 ;
    vis[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < v[now].size(); i++)
        {
            int nxt = v[now][i].second;
            int w = v[now][i].first;
            if(!vis[nxt])
            {
                vis[nxt] = 1;
                dis[nxt] = dis[now] + w;
                q.push(nxt);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int st, ed, w;
        cin >>st >> ed >> w;
        v[st].push_back(P(w, ed));
        v[ed].push_back(P(w, st));
    }
    bfs(1);
    color[1]  =1;
    for(int i = 2; i <= n; i++)
    {
        if(dis[i] % 2 == 0)
        {
            color[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << color[i] << endl;
    }
    return 0;
}