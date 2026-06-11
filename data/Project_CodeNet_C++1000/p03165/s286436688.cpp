 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007
ll dp[3005][3005];
int main()
{
    string s,d;
    cin>>s>>d;

    ll n=s.size();
    ll m=d.size();
    //memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
           if(s[i]==d[j])
           {
               dp[i][j]=1+dp[i+1][j+1];
           }
           else
           {
               ll op1=dp[i+1][j];
               ll op2=dp[i][j+1];

               dp[i][j]=max({dp[i][j],op1,op2});
           }
        }
    }
    //cout<<dp[0][0]<<endl;
    int i=0,j=0;
    string k;
    while(i<n && j<m)
    {
        if(s[i]==d[j])
        {
            k.push_back(s[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j]==dp[i][j])
        {
            i++;
        }
        else
        {
            j++;
        }

    }
   cout<<k<<endl;
   /*
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            //cout<<i<<"->"<<endl;
            //cout<<j<<"->"<<endl;
            cout<<dp[i][j]<< " ";
            //cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    //cout<<dp[2][6]<<endl;*/
}