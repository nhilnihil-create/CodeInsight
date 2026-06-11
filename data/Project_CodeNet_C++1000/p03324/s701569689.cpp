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
    ll d,n;
    cin>>d>>n;
    if(d==0){
        if(n==100)cout<<"101";
        else cout<<n;
    }
    else if(d==1){
        if(n==100)cout<<"101";
        else cout<<n;
        cout<<"00";
    }
    else{
        if(n==100)cout<<"101";
        else cout<<n;
        cout<<"0000";
    }
}
