#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    if(k==0) {
        cout<<1ll*n*n<<endl;
        return 0;
    }
    ll ans=0;
    for(int i=k+1;i<=n;i++){
        int x=n/i;
        int y=n%i;
        ans+=1ll*x*(i-k);
        if(y>=k )
        ans+=y-k+1;
    }
    cout<<ans<<endl;
    return 0;
}
