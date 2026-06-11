#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N; cin>>N;
    int h[N],now[N];
    rep(i,N)cin>>h[i];
    int stop[N];
    rep(i,N){
        if(h[i]==0)stop[i]=1;
        else stop[i]=0;    
        now[i]=0;
    }
    int ans=0;
    while(1){
        int cnt=1,flag=1;
        rep(i,N){
            if(flag==0&&stop[i]==1){
                cnt++;
                flag=1;
            }
            if(flag==1&&stop[i]==0)flag=0;
            if(stop[i]==0)now[i]++;
            if(flag==1&&i==N-1)cnt--;
        }
        ans+=cnt;
        rep(i,N)if(now[i]==h[i]&&stop[i]==0)stop[i]=1;
        int fin=0;
        rep(i,N)if(stop[i]==1)fin++;
        if(fin==N)break;
    }
    cout<<ans<<endl;
    return 0;
}