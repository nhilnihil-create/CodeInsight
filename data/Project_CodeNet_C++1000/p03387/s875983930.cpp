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

    ll i,j,a[3],diff;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    diff=a[2]-a[0]+a[2]-a[1];
    if(diff%2==0){
        cout<<diff/2<<endl;
    }
    else{
        diff++;
        cout<<diff/2+1<<endl;
    }
    return 0;
}



