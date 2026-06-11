#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define all(v) v.begin(),v.end() 
#define rev(v) v.rbegin(),v.rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define inp 100005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

signed main() 
{
    ssd
    string s1,s2;
    cin>>s1>>s2;
    int i,j,k,n1 = s1.length(), n2 = s2.length();
    s1 = "0" + s1; 
    s2 = "0" + s2;
    vector<vector<int>> dp(n1+5,vector<int> (n2+5,0));

    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }   
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    deque<char> ans;
    i = n1, j = n2;
    while(i!=0 && j!=0)
    {
        if(s1[i]==s2[j])
        {
            ans.push_front(s1[i]);
            i = i-1;
            j = j-1;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1]) i = i-1;
            else j = j-1;
        }
    }
    for(auto it:ans) cout<<it;
    return 0;           
}