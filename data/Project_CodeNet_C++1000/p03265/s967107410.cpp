#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    ll d=y2-y1;
    ll q=x2-x1;
    ll x3=x2-d;
    ll x4=x1-d;
    ll y3=y2+q;
    ll y4=y1+q;
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;


}
