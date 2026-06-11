#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<int>> edge(n);
    vector<bool> visited(n,false);
    vector<int> ans(n);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> c(n);
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    sort(all(c));
    cout<<sum-c.back()<<endl;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now=que.front();
        ans[now]=c.back();
        c.pop_back();
        visited[now]=true;
        for(auto next:edge[now]){
            if(!visited[next]){
                que.push(next);
            }
        }
        que.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}