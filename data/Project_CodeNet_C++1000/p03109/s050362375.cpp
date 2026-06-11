//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,a,b,c;
    string s,yr,dd,mm;
    cin>>s;
    yr=s.substr(0,4);
    mm=s.substr(5,2);
    dd=s.substr(8,2);
    a=stoi(yr);
    b=stoi(mm);
    c=stoi(dd);
    if(a<=2019&&b<=4)
    cout<<"Heisei"<<endl;
    else cout<<"TBD"<<endl;



    return 0;
}



