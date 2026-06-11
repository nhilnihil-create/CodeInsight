#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,K;
    cin>>N>>K;
    int ans=1;
    rep(i,N){
        if(ans<K)ans*=2;
        else ans+=K;
    }
    cout<<ans<<endl;
    return 0;
}