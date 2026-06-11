#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int n,a,b; cin>>n>>a>>b;
    int k;
    int ans=0;
    for(int i=1;i<=n;i++){
        k=0;
        int m=i;
        while(m>0){
            k+=m%10;
            m=m/10;
        }
        if(a<=k&&k<=b){
            ans+=i;
        }
    }
    cout<<ans<<endl;
    
}
