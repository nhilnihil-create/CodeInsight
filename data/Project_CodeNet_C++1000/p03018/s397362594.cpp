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


 main()

{
    fast
    string s;
    cin>>s;
    int sz=s.size();
    string yo="";
    s+="#";
    for(int i=0;i<sz;i++)
    {
         if(s[i]=='A')yo+=s[i];
         else if(s[i]=='B' && s[i+1]=='C')yo+='Z',i++;
         else if(s[i]!='#')yo+=s[i];
    }
    yo+="#";
    //cout<<yo<<endl;
    sz=yo.size();
    yo+="#####";
    int a=0,z=0,ses=0,flag=0;
    for(int i=0;i<sz;i++)
    {
        if(yo[i]=='A')
        {
            a++;
            if(yo[i+1]=='A' || (yo[i+1]=='Z') )continue;
            else
            {
                a=0;
            }
        }
        else if(yo[i]=='Z')
        {
            z++;
            if(yo[i+1]=='Z')continue;
            else if(yo[i+1]=='A')
            {
                ses+=(a*z);
                z=0;
            }
            else
            {
                ses+=(a*z);
                a=0;
                z=0;
            }
        }
        else
        {
            ses+=(a*z);
            a=0;
            z=0;
        }
    }
    cout<<ses<<endl;
    return 0;

}











