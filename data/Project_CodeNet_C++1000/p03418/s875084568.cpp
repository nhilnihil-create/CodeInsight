#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

int main(){
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    for (int b = k+1; b <= n; b++)
    {
        
        ans += (n/b)*(b-k);
        //cout<<"a"<<ans<<endl;
        if(n+1-(b*(n/b)+k)>0&&n%b!=0&&k!=0)ans += n+1-(b*(n/b)+k);
        else if(n+1-(b*(n/b)+k)>0&&n%b!=0&&k==0)ans += n-(b*(n/b)+k);
       // printf("b %d n/b %d \n",b,n/b);
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
    return 0;
}