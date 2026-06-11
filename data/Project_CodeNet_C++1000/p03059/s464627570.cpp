#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    double t;
    cin>>a>>b>>t;
    t+=0.5;
    int i=1,ans=0;
    while(a*i<t){
        ans+=b;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
