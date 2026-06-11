#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    ll n,ans=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        ll j=i;
        while(j<=n){
            j*=i;
        }
        j/=i;
        if(j!=i){
            ans=max(ans,j);
        }
    }
    cout<<ans<<endl;
}
