#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
#define M 1000000007
#define boost
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}

ll T;
string s1;
string s2;
int dp[3001][3001];
int lcs(int i,int j)
{
    if(i==0 || j==0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s1[i-1]==s2[j-1])
    {      
        return dp[i][j]=1+lcs(i-1,j-1);
    }

    return dp[i][j]=max(lcs(i-1,j),lcs(i,j-1));
}


int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
   
    cin>>s1;
    cin>>s2;
    string ans;
    memset(dp,-1,sizeof(dp));
   lcs(s1.size(),s2.size());
    int i=s1.size();
    int j=s2.size();
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
              ans.push_back(s1[i-1]);
              i--;
              j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
      reverse(ans.begin(),ans.end());
      //ans.erase(0,1);
    cout<<ans<<endl;


return 0;
}