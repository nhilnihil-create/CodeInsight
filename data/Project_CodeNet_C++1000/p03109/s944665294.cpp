#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
//string s,p;
//vector<int>v;
//map<int,int>mp;
int main()
{
    ft
    int t,i,j,n,m,l,r;
    string s;
    cin>>s;
    s+="/";
    n=s.size();
    l=r=m=0;
    for(i=0; i<n; i++)
    {
        if(s[i]=='/')
        {
            if(r==0)
            {
                if(l<2019)
                {
                    m=1;
                    break;
                }
                else if(l>2019)
                {
                    m=0;
                    break;
                }
                r++;
            }
            else if(r==1)
            {
                if(l<4)
                {
                    m=1;
                    break;
                }
                else if(l>4)
                {
                    m=0;
                    break;
                }
                r++;
            }
            else
            {
                if(l<=30)
                {
                    m=1;
                    break;
                }
                else if(l>30)
                {
                    m=0;
                    break;
                }
            }
            l=0;
        }
        else
        {
            l=(l*10)+s[i]-48;
        }
    }
    (m==1)? cout<<"Heisei\n": cout<<"TBD\n";
    return 0;
}

