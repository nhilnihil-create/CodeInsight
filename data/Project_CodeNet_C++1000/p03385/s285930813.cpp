//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep(i,n)    for(ll i=1; i<=n; i++)
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

    ll i,j,k,a=0,b=0,c=0;
    string s;
    cin>>s;
    for(i=0; s[i]; i++)
    {
        if(s[i]=='a')
            a++;
        else if(s[i]=='b')
            b++;
        else if(s[i]=='c')
            c++;

    }
    if(a&&b&&c)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;






    return 0;
}



