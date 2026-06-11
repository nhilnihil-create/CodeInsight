#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int N,K;
ll ans;
int main(){
    cin>>N>>K;
    for(int i=K+1;i<=N;i++){
        ans+=N/i*(i-K)+max(N%i-K+1,0);
    }
    if(K==0)ans-=N;
    cout<<ans<<'\n';
    return 0;
}

