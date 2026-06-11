#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back

int main()
{

    int i,j;
    int q;
    cin>>q;
    while(q--)
    {

        ll a,b;
        cin>>a>>b;
        ll a1,b1;
        a1=min(a,b);
        b1=max(a,b);

        if(a1==b1)
        {
            ll x=2*a1-2;
            cout<<x<<endl;
        }
        else
        {

            ll pr=(ll)a1*b1;
            ll q=(ll)sqrt(pr);

            ll w=q*q;
            if(w==pr)
                q--;

            int fl=0;
            ll ans=2*q-1;
            ll p=(q)*(q+1);
            if(p>=pr)
                fl=1;
            ans=ans-fl;
            cout<<ans<<endl;




        }





    }














    return 0;
}
