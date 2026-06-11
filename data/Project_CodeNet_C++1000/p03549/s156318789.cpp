#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    ll n;cin>>n;
    ll m;cin>>m;
    ans=100*(n-m)+1900*m;
    For(i,0,m) ans*=2;
    cout<<ans<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}