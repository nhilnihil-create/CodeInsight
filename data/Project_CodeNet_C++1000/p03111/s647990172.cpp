#include <bits/stdc++.h>
using namespace std;
int N,A,B,C;
vector<int> L;
int ans=(1<<30);
void dfs(int cur,int a,int b,int c,int mp){
    if(cur==N){
        if(a>0&&b>0&&c>0){
            ans=min(ans,abs(a-A)+abs(b-B)+abs(c-C)+mp-30);
        }
        return;
    }
    dfs(cur+1,a+L[cur],b,c,mp+10);
    dfs(cur+1,a,b+L[cur],c,mp+10);
    dfs(cur+1,a,b,c+L[cur],mp+10);
    dfs(cur+1,a,b,c,mp);
}
int main(){
    cin>>N>>A>>B>>C;
    for(int i=0;i<N;i++){
        int k;cin>>k;
        L.push_back(k);
    }
    dfs(0,0,0,0,0);
    cout<<ans<<endl;
}