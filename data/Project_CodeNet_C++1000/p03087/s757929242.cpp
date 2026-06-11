//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll  i,j,k,l,r,n,q,ans;
    string s;
    cin>>n>>q>>s;

    vector<ll>Till_I(n,0);
    ll cnt=0;
        for(i=1; i<s.size(); i++)
        {
            if(s[i-1]=='A'&&s[i]=='C')
             cnt++;
             Till_I[i]=cnt;
        }
    while(q--)
    {
        ans=0;
        cin>>l>>r;

        cout<<Till_I[r-1]-Till_I[l-1]<<endl;
    }



    return 0;
}



