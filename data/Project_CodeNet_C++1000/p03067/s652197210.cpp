//Radhe Radhe
#include<bits/stdc++.h>//157B
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll i,j,a,b,c,mini,maxi;
    cin>>a>>b>>c;
    mini=min(a,b);
    maxi=max(a,b);
    if(c>=mini&&c<=maxi){
    return cout<<"Yes"<<endl,0;
    }
    cout<<"No"<<endl;



    return 0;
}



