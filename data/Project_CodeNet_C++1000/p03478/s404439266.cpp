#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,s=0,x;
    cin>>n>>a>>b;x=a;

    for(int i=1;i<=n;i++){
        ll s2=0,y;y=i;
        while(y>0){
            s2+=(y%10);y/=10;
        }
        if(s2>=a&&s2<=b){s+=i;}
    }
    cout<<s<<endl;
}
