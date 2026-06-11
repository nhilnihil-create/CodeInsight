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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t,r=1,r1=0,r2=0,k=0,a,b,c=1,m,n,e,f,x=0,g,p=0,q=0,y=0,z=0;
    char d;
    vector<long long>v;
    vector<long long>u;
    set<string>s;
    std::vector<int>::iterator it;
    string  s1,s2,s3,s4;
    cin>>n>>s1;
    s.in(s1);
     d=s1[s1.size()-1];
    l(i,1,n)
    {
        cin>>s1;
        if(s1[0]==d)
        {
            x++;

        }
         d=s1[s1.size()-1];
          s.in(s1);
        //cout<<d<<endl;

    }



//cout<<x<<" "<<s.size()<<endl;
//for(auto x:s)
//{
//    cout<<x<<endl;
//}


    (s.size()==n&&x==n-1)?cout<<"Yes":cout<<"No"
;}
