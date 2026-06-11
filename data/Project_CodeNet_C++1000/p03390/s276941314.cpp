#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll a,b,q,ans;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        if(a==b)
        {
            ans=(a-1)*2;
            cout<<ans<<endl;
            continue;
        }
        if(a>b) swap(a,b);
        if(a==1 && b==2)
        {
            cout<<0<<endl;
            continue;
        }
        ll t=(ll)sqrt(a*b-1);
      //  cout<<"t="<<t<<endl;
        ll k=t;
        while(k*t<a*b) k++;
        k--;
        if(k-t>=2) k=t+1;
        //cout<<"k="<<k<<endl;
        ans=k+t-1;
        int tmp=ans;
        if(a<tmp) ans--;
        if(b<tmp) ans--;
       // cout<<"ans="<<ans<<" "<<ans-a<<" "<<ans-b<<" ";
      //  cout<<(ans-a)*(ans-b)<<" "<<a*b<<endl;
        if(tmp-a>0 && tmp-b>0 && (tmp-a)*(tmp-b)<a*b)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
