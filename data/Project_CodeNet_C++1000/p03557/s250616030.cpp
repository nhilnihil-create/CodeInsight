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
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,x,j,k,n,cnt=0;
    string s;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(i=0; i<n; i++)
        cin>>a.at(i);
    for(i=0; i<n; i++)
        cin>>b.at(i);
    for(i=0; i<n; i++)
        cin>>c.at(i);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    // a< b <c
    for(i=0; i<n; i++)
    {
        auto it1=lower_bound(a.begin(),a.end(),b.at(i));
        ll num=it1-a.begin();
        auto it2=upper_bound(c.begin(),c.end(),b.at(i));
        cnt+=num*(c.end()-it2);
    }

    cout<<cnt<<endl;
    return 0;
}



