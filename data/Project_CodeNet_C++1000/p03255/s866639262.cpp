#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<20;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,X;cin>>N>>X;
    vector<ll> S(N+1);
    for(int i=0;i<N;i++){
        cin>>S[i+1];
        S[i+1]+=S[i];
    }
    
    ll ans=INF;
    
    for(int k=1;k<=N;k++){
        ll sum=X*(N+k);
        sum+=2*(S[N]-S[N-k]);
        ll now=N;
        for(ll j=1;j<=(N+k-1)/k;j++){
            sum+=(2*j+1)*(S[now]-S[max(0LL,now-k)]);
            now-=k;
            
            if(sum>ans) break;
        }
        
        ans=min(ans,sum);
    }
    
    cout<<ans<<endl;
}
