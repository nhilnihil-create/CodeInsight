#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
void solve(){
    if(a+b>n+1||a*b<n){
        puts("-1");
        return ;
    }
    while(n>0){
        ll x=min(a,n-b+1);
        for(ll i=n-x+1;i<=n;i++)
            cout<<i<<" ";
        n-=x;
        b--;
    }
}
int main(){
    while(cin>>n>>a>>b)
    {
        solve();
        cout<<endl;
    }
    return 0;
}