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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll s=1,x;
    cin>>h;
    if(h==1)cout<<1<<endl;
    for(int i=2;i<=32;i++){x=i;//cout<<x<<endl;
    //if(x<=h)s=max(s,x);
        while(x<=1000){
            x*=i;//cout<<x<<endl;
            if(x<=h)s=max(s,x);
        }
    }
    if(h!=1)cout<<s;
}
