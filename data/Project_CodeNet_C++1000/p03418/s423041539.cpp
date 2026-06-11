#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    ll n,k;cin>>n>>k;
    ll res=0;
    if(k==0){cout<<n*n<<endl;return 0;}
    for(ll b=k+1;b<=n;b++){
        res+=(n/b)*(b-k)+max(0LL,n-(n/b)*b-k+1);
    }
    cout<<res<<endl;
    return 0;
}