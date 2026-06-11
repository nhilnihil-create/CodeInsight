#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

main()
{
        string s; cin>>s;
        string t="AKIHABARA";
        if(s.size()>t.size())
        {
                cout<<"NO"<<endl;
                return 0;
        }
        int id=0;

        if(s[id]=='A')id++;

        if(s[id]=='K')id++;
        else return cout<<"NO"<<endl,0;

        if(s[id]=='I')id++;
        else return cout<<"NO"<<endl,0;

        if(s[id]=='H')id++;
        else return cout<<"NO"<<endl,0;

        if(s[id]=='A')id++;

        if(s[id]=='B')id++;
        else return cout<<"NO"<<endl,0;

        if(s[id]=='A')id++;

        if(s[id]=='R')id++;
        else return cout<<"NO"<<endl,0;

        if(s[id]=='A')id++;

        cout<<"YES"<<endl;
}