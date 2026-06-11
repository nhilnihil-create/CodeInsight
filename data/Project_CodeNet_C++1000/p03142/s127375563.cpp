#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,m,a,b,num[100009],ans[100009];
vector<ll>e[100009];

int main(){
    cin>>n>>m;
    rep(i,n-1+m){
        cin>>a>>b;
        e[a].push_back(b);
        num[b]++;
    }
    queue<ll> que;
    FOR(i,1,n+1)if(num[i]==0)que.push(i);
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        rep(i,e[now].size()){
            num[e[now][i]]--;
            if(num[e[now][i]]==0){
                ans[e[now][i]]=now;
                que.push(e[now][i]);
            }
        }
    }
    FOR(i,1,n+1)cout<<ans[i]<<endl;
}
