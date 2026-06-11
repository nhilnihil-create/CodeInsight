///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


 main()

{
    fast
    string s;
    cin>>s;
    map<char,bool>vis;
    string chk="";
    for(char ch='z';ch>='a';ch--)chk+=ch;
    for(char x:s)
    {
       vis[x]=true;
    }
    if(s==chk)
    {
        cout<<"-1"<<endl;
    }
    if(s.size()==26)
    {
        for(int i=25;i>=0;i--)
        {
            int flag=0;
            char ok;
            for(int j=i+1;j<26;j++)
            {
                if(s[j]>s[i])
                {
                    if(flag==0)ok=s[j];
                    else if(s[j]<ok)ok=s[j];
                    flag=1;
                }
            }
            if(flag==1)
            {
                string ses=s.substr(0,i);
                ses+=ok;
                cout<<ses<<endl;
                return 0;
            }
        }
    }
    else
    {
       for(char ch='a';ch<='z';ch++)
       {
           if(vis[ch]!=true)
           {
               s+=ch;
               break;
           }
       }
       cout<<s<<endl;
    }
    return 0;

}



































