#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;
int n;
int ara[]={3,5,7};
int dfs(ll num)
{
//    cout<<"num = "<<num<<endl;
    if(num>n)return 0;
    ll temp=num;
    int t=0,p=0,s=0;
    while(temp>0){
        int d=temp%10;
        temp/=10;
        if(d==3)t=1;
        else if(d==5)p=1;
        else if(d==7)s=1;
    }
    int res=0;
    if(t&p&s)res=1;
    for(int i=0;i<3;i++)
        res+=dfs(num*10+ara[i]);
    return res;
}
int main()
{
    IOS;
    cin>>n;
    cout<<dfs(0)<<endl;
}






