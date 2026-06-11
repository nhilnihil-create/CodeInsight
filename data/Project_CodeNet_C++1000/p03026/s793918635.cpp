#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){
int N;
cin>>N;
vector<vector<int>>to(N);
vector<pair<int,int>>bre(N-1);
int cnt[N]={};
rep(i,N-1){
    int a,b;
    cin>>a>>b;
    a--,b--;
    bre[i]=make_pair(a,b);
    to[a].emplace_back(b);
    to[b].emplace_back(a);
    cnt[a]++;
    cnt[b]++;
}
vector<long long >c(N);
rep(i,N){
    cin>>c[i];
}
sort(c.begin(),c.end());
multimap<int,int>v;
rep(i,N){
    v.insert(make_pair(-cnt[i],i));
}
auto iter=v.begin();
int start=iter->second;

int p=N-1;
bool checked[N]={};
long long ans[N];
queue<int>q;
q.push(start);
checked[start]=true;

while(!q.empty()){
    int now=q.front();
    q.pop();
    ans[now]=c[p];
    p--;
    for(auto vp:to[now]){
        if(checked[vp])continue;
        checked[vp]=true;
        q.push(vp);
    }
}
long long M=0;
rep(i,N-1){
M+=min(ans[bre[i].first],ans[bre[i].second]);
}

cout<<M<<endl;

rep(i,N){
    cout<<ans[i]<<" ";
}


 return 0;
}
/*

by my self
first       1h 21m 37s
second         20m 49s

5
1 2
2 3
3 4
4 5
1 2 3 4 5

10
1 2 3 4 5


5
1 2
1 3
1 4
1 5
3141 59 26 53 59

197
59 26 3141 59 53

*/