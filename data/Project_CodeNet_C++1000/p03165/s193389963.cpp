#include <iostream>
#include <algorithm>

using namespace std;

int32_t main()
{
	string s, t, ans;
    cin >> s >> t;
    int dp[s.size()+1][t.size()+1];
    for(int i = 0; i <= s.size(); i++)
    {
    	for(int j = 0; j <= t.size(); j++)
        {
        	if(i == 0 || j == 0)
            {
              	dp[i][j] = 0;
            	continue;
            }
          	if(s[i-1] == t[j-1])
            	dp[i][j] = dp[i-1][j-1]+1;
          	else
            	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = s.size(), j = t.size();
    while(i > 0 && j > 0)
    {
        if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j] == dp[i][j-1])
            j--;
        else
            i--, j--, ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
  	return 0;
}