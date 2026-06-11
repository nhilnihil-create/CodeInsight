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

int main()
{
    IOS;
    string s;cin>>s;
    int n=s.length();
    int l=0,r=n-1;
    int ans=0;
    while(l<=r)
    {
        if(s[l]==s[r])l++,r--;
        else if(s[l]=='x')l++,ans++;
        else if(s[r]=='x')r--,ans++;
        else{
            ans=-1;
            break;
        }
    }
    cout<<ans<<endl;
}






