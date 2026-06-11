#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int to,costa,costb;};

signed main() {
int n;
cin>>n;
int t[n+1],t0;t[0]=0;
for(int i=0;i<n;i++){
    cin>>t0;
    t[i+1]=t[i]+2*t0;
}
int ans[t[n]+1];
for(int i=0;i<=t[n];i++)ans[i]=min(i,t[n]-i);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;int v;
for(int i=0;i<n;i++){
    cin>>v;
    que.push(make_pair(2*v,i));
}
pair<int,int>q;
while(!que.empty()){
    q=que.top();que.pop();
    for(int i=t[q.second];i<=t[q.second+1];i++)ans[i]=min(ans[i],q.first);
    for(int i=t[q.second]-1;i>=0&&ans[i]>ans[i+1]+1;i--)ans[i]=ans[i+1]+1;
    for(int i=t[q.second+1]+1;i<=t[n]&&ans[i]>ans[i-1]+1;i++)ans[i]=ans[i-1]+1;
}
float ans2=0;for(int i=0;i<=t[n];i++)ans2+=ans[i];
cout << std::setprecision(20)<<ans2/4;


return 0;


}
