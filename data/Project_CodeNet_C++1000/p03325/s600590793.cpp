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
    ll n;
    cin>>n;
    ll a,x=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        while(a%2==0)a/=2,x++;
        //x+=(ll)log2(a);
    }
    cout<<x;
}
