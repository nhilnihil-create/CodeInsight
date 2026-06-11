/*
START BY THE NAME OF ALMIGHTY ALLAH
THIS WONT BE ACCEPTED
STOP_GIVING_UP

██╗███████╗████████╗██╗ █████╗ ██╗  ██╗
██║██╔════╝╚══██╔══╝██║██╔══██╗██║ ██╔╝
██║███████╗   ██║   ██║███████║█████╔╝
██║╚════██║   ██║   ██║██╔══██║██╔═██╗
██║███████║   ██║   ██║██║  ██║██║  ██╗
╚═╝╚══════╝   ╚═╝   ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝




*/
#include<bits/stdc++.h>
#define l(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define in insert
#define mp make_pair
#define lw(v) sort(v.begin(),v.end());
#define hi(v) sort(v.begin(),v.end(),greater<long long>());
#define all(v) v.begin(),v.end()
#define filein freopen ("input.txt", "r", stdin)
#define fileout freopen ("output.txt", "w", stdout)
using namespace std;
bool sortbyval(const tuple<string,int,int>&a,const tuple<string,int,int>&b)
{
if( get<0>(a)!=get<0>(b))
    {
        return  (get<0>(a)<get<0>(b));
    }

    return  get<1>(a)>get<1>(b);
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t,r=1,r1=0,r2=0,k=0,a,b,c=1,m,d=0,n,e,f,x=0,g,p=0,q=0,y=0,z=0;
    vector<long long>v;
    vector<long long>u;
    vector<tuple<string,int,int>>mp;
    set<long long>s;
    std::vector<int>::iterator it;
    string  s1,s2,s3,s4;
    cin>>n;
l(i,1,n+1)    {
        cin>>s1>>m;
       mp.pb(make_tuple(s1,m,i));
    }
    sort(all(mp),sortbyval);
    for(auto x:mp)
    {
        cout<<get<2>(x)<<endl;
    }

    }
