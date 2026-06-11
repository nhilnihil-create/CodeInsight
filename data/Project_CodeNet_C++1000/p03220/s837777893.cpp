#include<bits/stdc++.h>
#include<tuple>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t,a,x;double y=1e18;
    cin>>n>>t>>a;
    ll h[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i];
        double av=t-(h[i]*0.006);
        if(abs(av-a)<y)y=abs(av-a),x=i;
    }
    cout<<x<<endl;
}
