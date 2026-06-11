#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,x2,y2,a,b;
    cin>>x>>y>>x2>>y2;
    a=x2-x,b=y2-y;
    cout<<(x2-b)<<" "<<(y2+a)<<" ";
    cout<<(x-b)<<" "<<(y+a)<<endl;
}
