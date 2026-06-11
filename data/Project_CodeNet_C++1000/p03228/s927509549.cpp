//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define en '\n'
#define rep(i,n)    for(ll i=0; i<n; i++)
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(1);
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll i,a,b,k;
    string s;
    cin>>a>>b>>k;
    for(i=1; i<=k; i++)
    {
        if(i%2)
        {
            if(a%2)
                a--;
                b+=a/2;
                a/=2;

    // cout<<1<<" "<<a<<" "<<b<<endl;
        }
        else
        {
            if(b%2)
                b--;

                a+=b/2;
                b/=2;
     //cout<<2<<" "<<a<<" "<<b<<endl;
        }

    }
     cout<<a<<" "<<b<<endl;

    return 0;
}



