#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,w;
ll direction2[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
bool valid(int a,int b)
{
    if(a>=1&&a<=h&&b>=1&&b<=w)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x=1,y,s=0;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        s+=l1[i];
//        if(i>=1){
//            y=x;
//            x=__gcd(x,l1[i]);
//            x=(ll)(l1[i]*(y/x));
//        }
    }//cout<<x<<endl;
//    for(int i=1;i<=n;i++){
//        s+=(x-1)%l1[i];
//    }
    cout<<s-n;
}
