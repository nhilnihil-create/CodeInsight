#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

//    cin>>t;
//    while(t--){
        ll n,k,y=1,z=1e18;
        cin>>n>>k;
        ll l1[n+1];
        for(int i=1;i<=n;i++)cin>>l1[i];
        for(int i=1;i<=n-k+1;i++){
            z=min(z,abs(l1[i])+abs(l1[i+k-1]-l1[i]));
            z=min(z,abs(l1[i+k-1])+abs(l1[i+k-1]-l1[i]));
            //cout<<abs(l1[i])+abs(l1[i+k-1]-l1[i])<<endl;
        }
        cout<<z;
    //}
}
