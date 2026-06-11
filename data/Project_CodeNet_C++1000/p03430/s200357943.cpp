#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const int M=301;
int n,m,x,y;
int dp[M][M][M];
string s;
int calc(int i,int j,int c){
    if(c<0)return -1e9;
    if(j<=i)return j==i;
    int &k=dp[i][j][c];
    if(k!=-1)return k;
    k=max(calc(i+1,j,c),calc(i,j-1,c));
    return k=max(k,2+calc(i+1,j-1,c-(s[i]!=s[j])));
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>s>>x;
    n=s.size();
    cout<<calc(0,n-1,x);
    return 0;
}
