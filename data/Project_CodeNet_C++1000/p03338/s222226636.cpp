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
    ll n,x=0,ct=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<n;i++){
        for(char j='a';j<='z';j++){bool l=false,r=false;
            for(int k=0;k<i;k++)if(s[k]==j){l=true;break;}
            for(int k=i;k<n;k++)if(s[k]==j){r=true;break;}
            if(l&&r)ct++;
        }
        x=max(x,ct);ct=0;
    }
    cout<<x<<endl;
}
