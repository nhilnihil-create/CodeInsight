#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll a,b,c,d,s,t;
    cin>>a>>b>>c>>d;
    s=a+b;
    t=c+d;
    if(s<t)
        cout<<"Right"<<endl;
    else if(s>t)
        cout<<"Left"<<endl;
    else
        cout<<"Balanced"<<endl;

    return 0;
}



