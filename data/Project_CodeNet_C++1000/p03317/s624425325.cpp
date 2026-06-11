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
    ll n,k;
    cin>>n>>k;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    ll j=0;
    while(1){
        if((k*(j+1)-j)>=n){
            cout<<j+1;return 0;
        }j++;
    }
}
