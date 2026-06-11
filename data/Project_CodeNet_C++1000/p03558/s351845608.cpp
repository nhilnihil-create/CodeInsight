#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int k; cin>>k;
    int ans[k]; rep(i,k) ans[i]=INF;
    deque<pair<int,int>> dq;
    dq.push_front({1,1});
    while(dq.size()){
        auto e=dq.front(); dq.pop_front();
        int cost=e.first,num=e.second;
        if(cost<ans[num]){
            ans[num]=cost;
            dq.push_front({cost,(num*10)%k});
            dq.push_back({cost+1,(num+1)%k});
        }
    }
    cout<<ans[0]<<endl;
    return 0;
}
