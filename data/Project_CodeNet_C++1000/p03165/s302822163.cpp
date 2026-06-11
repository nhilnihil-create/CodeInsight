#include<iostream> 
#include<cstring> 
#include<algorithm>

#define kkpareek ios_base::sync_with_stdio(0); cin.tie(0); 
using namespace std;

int dp[3001][3001];

int getLen(string& s, string& t, int i, int j)
{
    if(i >= s.size() || j >= t.size()) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i] == t[j]) return dp[i][j] = 1 + getLen(s,t,i+1,j+1);
                     return dp[i][j] = max(getLen(s,t,i+1,j), getLen(s,t,i,j+1));
}

string getLcs(string& s, string& t, int len)
{
    string ret; int i=0,j=0;
    
    while(len > 0)
    {
        if(s[i] == t[j])
        {
            ret.push_back(s[i]);
            ++i; ++j; --len;
        }
        
        else
        {
            if(dp[i+1][j] > dp[i][j+1]) i++;
            else j++;
        }
    }
    return ret;
}

string ans(string& s, string& t)
{
    int len = getLen(s,t,0,0);
    return getLcs(s,t,len);
}

int main()
{
    kkpareek;
    memset(dp, -1, sizeof(dp));
    
    string s,t; cin >> s >> t;
    cout << ans(s,t);
}
 
