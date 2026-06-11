#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s;
        cin>>t;
        int n=s.size(),m=t.size();
        vector<vector<int> > a(n);
        for(int i=0;i<n;i++)
        {
            a[i].resize(m,0);
            for(int j=0;j<m;j++)
            {
                if(s[i]==t[j])
                {
                    if(i!=0&&j!=0)
                    {
                        a[i][j]=1+a[i-1][j-1];
                    }
                    else
                    {
                        a[i][j]=1;
                    }
                }
                else
                {
                    if(i!=0)
                    a[i][j]=max(a[i-1][j],a[i][j]);
                    if(j!=0)
                    a[i][j]=max(a[i][j-1],a[i][j]);
                }
            }
        }
        string s1="";
        int i=n-1,j=m-1;
        while(a[i][j])
        {
            if(i==0)
            {
                s1.push_back(s[i]);
                break;
            }
            if(j==0)
            {
                s1.push_back(t[j]);
                break;
            }
            if(a[i-1][j]==a[i][j])
            {
                i--;
            }
            else if(a[i][j-1]==a[i][j])
            {
                j--;
            }
            else
            {
                s1.push_back(s[i]);
                i--,j--;
            }
        }
        reverse(s1.begin(),s1.end());
        cout<<s1<<"\n";
    }
    return 0;
}