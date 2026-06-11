#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int LCS(string,string);
int dp[3001][3001];
vector<char> ans;
 
signed main(){
    fast
 
    string s,t;
    cin>>s>>t;
    LCS(s,t);
    for(auto x:ans) cout<<x;
}
 
int LCS(string s,string t){
    f1(i,0,s.size())
        f1(j,0,t.size()){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    
    int i=s.size(),j=t.size();
    while(i!=0&&j!=0){
        if(s[i-1]==t[j-1]){
            ans.pb(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    return dp[s.size()][t.size()];
}