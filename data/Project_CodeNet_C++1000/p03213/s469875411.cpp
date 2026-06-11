#include<bits/stdc++.h>
using namespace std;

bool prime[105];
 vector<pair<int,int> >v;

void seive()
{
    for(int i=1;i<=105;i++)prime[i]=true;
    for(int i=2;i*i<=105;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2;j<=105;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

int f(int pos,int sum)
{
     if(sum>75)return 0;
     if(sum==75)return 1;
     if(pos==v.size())return 0;

    int ans=0;

    for(int i=0;i<=v[pos].second;i++)
    {
        ans+=f(pos+1,sum*(i+1));
    }
    return ans;
}

int main()
{
    seive();
     int n;
     cin>>n;

     for(int i=2;i<=n;i++)
     {
         if(prime[i])
         {
             int a=i;
             int sum=0;
             while(a<=n)
             {
                 sum+=n/a;
                 a*=i;
             }
            // cout<<i<<" "<<sum<<endl;
             v.push_back(make_pair(i,sum));
         }
     }
     cout<<f(0,1)<<endl;
}
