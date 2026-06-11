/**
 *COYG, 14 FA Cups we are back baby
 */
#include <bits/stdc++.h>
using namespace std;
#define mod 		1000000007
#define ll 		long long
#define mp 		make_pair
#define pb 		push_back
#define forn(i,n) 	for(int i=0;i<n;i++)
#define for1(i,n) 	for(int i=1;i<n;i++)
#define ford(i,n) 	for(int i=n-1;i>=0;i--)
#define vi 		vector<int>
#define vl 		vector<ll>
#define pii 		pair<int,int>
#define pll 		pair<ll,ll>
#define vpi 		vector<pair<int,int> >
#define vpl		vector<pair<ll,ll> >
#define vvi 		vector<vector<int> >
#define vvl 		vector<vector<ll> >
#define ull 		unsigned long long
#define IOS 		ios_base::sync_with_stdio(false);
#define PI 		3.1415926535897932384626
#define ff 		first
#define ss 		second
#define char2Int(c) 	(c-'0')
#define FOREACH(i,t) 	for (auto i=t.begin(); i!=t.end(); i++)
#define clr(a,x) 	memset(a,x,sizeof(a)) //set elements of array to some value
#define all(x)		(x).begin(),(x).end()//cout<<"Case #"<<zzz<<": ";
#define plll pair<ll,pll >
double dp[301][301][301];int n;
double getans(int curr[])
{
    if(dp[curr[0]][curr[1]][curr[2]]!=-1)return dp[curr[0]][curr[1]][curr[2]];
    double mult=((double)n-(double)curr[0])/(double)n;
    mult=(double)1/mult;
    double ans=mult;
    for(int i=1;i<3;i++)
    {
        int curr1[3];forn(j,3)curr1[j]=curr[j];
        if(curr[i]>0)
        {
            --curr1[i];++curr1[i-1];
            ans+=mult*(((double)curr[i]/(double)n)*getans(curr1));
        }
    }
    if(n>curr[0]+curr[1]+curr[2])
    {
        int curr1[3];forn(j,3)curr1[j]=curr[j];
        ++curr1[2];
        ans+=mult*(((double)(n-(curr[0]+curr[1]+curr[2]))/(double)n)*getans(curr1));
    }
    dp[curr[0]][curr[1]][curr[2]]=ans;
    return ans;
}
void solve()
{
    cin>>n;
    forn(i,n+1)forn(j,n+1)forn(k,n+1)dp[i][j][k]=-1;int curr[3]={0,0,0};
    forn(i,n){int x;cin>>x;if(x==1)++curr[1];else if(x==2)++curr[2];}
    dp[n][0][0]=0;
    cout<<setprecision(16)<<getans(curr)<<endl;
}
int main()
{
    IOS;cin.tie(NULL);
    int zz;zz=1;
    //cin>>zz;
    for(int zzz=1;zzz<=zz;zzz++)
    {
        solve();
    }
    return 0;
}
