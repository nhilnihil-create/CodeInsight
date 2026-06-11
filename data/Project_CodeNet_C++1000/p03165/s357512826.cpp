#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e8;

string a,b;
int dp[3005][3005];

int f(int idxa,int idxb)
{
    if(idxa==a.size()||idxb==b.size())
        return dp[idxa][idxb]=0;
    int &ret=dp[idxa][idxb];
    if(ret!=-1)
        return ret;
    ret=f(idxa+1,idxb);
    if(a[idxa]==b[idxb])
        ret=max(ret,f(idxa+1,idxb+1)+1);
    ret=max(ret,f(idxa,idxb+1));
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>a>>b;
        memset(dp,-1,sizeof dp);
        f(0,0);
        string ans="";
        int idx1=0,idx2=0;
        while(idx1<a.size()&&idx2<b.size()){
            int ret=dp[idx1+1][idx2];
            ret=max(ret,dp[idx1][idx2+1]);
            if(a[idx1]==b[idx2])
                ret=max(ret,dp[idx1+1][idx2+1]+1);
            if(ret==dp[idx1+1][idx2])
                idx1++;
            else if(ret==dp[idx1][idx2+1])
                idx2++;
            else{
                ans+=a[idx1];
                idx1++;idx2++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
