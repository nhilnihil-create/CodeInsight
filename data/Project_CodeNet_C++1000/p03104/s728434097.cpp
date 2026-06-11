#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    ll ans1=0;
    a--;
    for(ll i=1;i<=a;i*=2)
    {
        //cout<<i<<" "<<a+1<<" "<<((a+1)/(i*2))*(i)<<" "<<(((a+1)%(i*2)>i)?((a+1)%i):0)<<endl;
        ll temp=((a+1)/(i*2))*(i)+(((a+1)%(i*2)>i)?((a+1)%i):0);
        if(temp%2==1)
        {
            ans1=ans1+i;
        }
    }
    //cout<<ans1<<endl;
    ll ans2=0;
    a=b;
    for(ll i=1;i<=b;i*=2)
    {
        //cout<<i<<" "<<a+1<<" "<<((a+1)/(i*2))*(i)<<" "<<(((a+1)%(i*2)>i)?((a+1)%i):0)<<endl;
        ll temp=((b+1)/(i*2))*(i)+(((b+1)%(i*2)>i)?((b+1)%i):0);
        if(temp%2==1)
        {
            ans2+=i;
        }
    }
    //cout<<ans2<<endl;
    cout<<(ans1^ans2);
	return 0;
}
