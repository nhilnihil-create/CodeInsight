//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,sum=0; cin>>n;
    vector<vector<int>> path(n);
    vector<int> ans(n,0),c(n,0);
    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    rep(i,n){
        cin>>c[i];
        sum+=c[i];
    }
    sort(al(c)); reverse(al(c));
    sum-=c[0];
    int cnt=0;
    queue<int> que;
    que.push(0);
    while(!(que.empty())){
        int s=que.front();
        que.pop();
        ans[s]=c[cnt]; 
        cnt++;
        for(auto to:path[s]){
            if(ans[to]==0) que.push(to);
        }
    }
    cout<<sum<<endl;
    rep(i,n-1) cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;
}
