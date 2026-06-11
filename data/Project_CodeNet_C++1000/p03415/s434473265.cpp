//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep(i,n)    for(ll i=0; i<n; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    ll i,j,n;
    char a[3][3];
    rep(i,3)
    {
    rep(j,3)
        cin>>a[i][j];
    }
    cout<<a[0][0]<<a[1][1]<<a[2][2]<<endl;
    return 0;
}



