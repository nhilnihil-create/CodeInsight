#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll a,b,c,x,s2=0;
    cin>>a>>b>>c>>x;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                ll s=500ll*i+100ll*j+50ll*k;
                if(s==x)s2++;
            }
        }
    }
    cout<<s2<<endl;
}
