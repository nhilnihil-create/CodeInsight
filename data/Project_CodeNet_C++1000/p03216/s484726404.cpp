#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){

  int N;cin>>N;
    string S;cin>>S;
    int Q;cin>>Q;
    vector<ll> cnt(N+1,0),appear(N+1,0);
    int mcnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='M') mcnt++;
        else if(S[i]=='C'){
            cnt[i+1]=mcnt;
            appear[i+1]=1;
        }
    }
    for(int i=1;i<=N;i++){
        cnt[i]+=cnt[i-1];
        appear[i]+=appear[i-1];
    }
    
    for(int i=0;i<Q;i++){
        int K;cin>>K;
        ll ans=0;
        int mdelete=0;
        for(int i=0;i<N;i++){
            if(S[i]=='M') mdelete++;
            else if(S[i]=='D'){
                int to=min(N,i+K);
                ans+=cnt[to]-cnt[i]-(appear[to]-appear[i])*mdelete;
            }
        }
        cout<<ans<<endl;
    }
    
}

