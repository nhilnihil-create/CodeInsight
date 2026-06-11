#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 500000000
#define IOS ios_base::sync_with_stdio(0)
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
bool check(int n,int p){return (1<<p)&n;}
vector<string>v;
string temp;
vector<string>x;
bool vis[20];
int n;
int main()
{
    IOS;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        v.pb(s);
    }
    int ba=0,_a=0,b_=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].length()-1;j++)
        {
            if(v[i][j]=='A'&&v[i][j+1]=='B')ans++;
        }
        int l=v[i].length();
        string s;
        s+=v[i][0];
        s+=v[i][l-1];
        if(s=="BA")ba++;
        else if(s[0]=='B')b_++;
        else if(s[1]=='A')_a++;
    }
//    cout<<ba<<" "<<_a<<" "<<b_<<endl;
    if(ba>0){
        ans+=ba-1;
        if(b_>0)b_--,ans++;
        if(_a>0)_a--,ans++;
    }
    ans+=min(_a,b_);

    cout<<ans<<endl;
}






