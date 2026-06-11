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
    ll a,b,x,y;map<ll,ll>m;
    cin>>a>>b;
    for(int i=1;i<999;i++){
        x=(i*(i+1))/2;
        y=((i+2)*(i+1))/2;
        if(x-a==y-b&&x-a>0&&y-b>0){
            cout<<y-b<<endl;return 0;
        }
    }

}
