#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ans = "";
    string s,t; cin >> s >> t;
    int m = s.length();
    int n = t.length();
    vector<vector<int>> grid(m+1, vector<int> (n+1,0));
    
     for(int i = 1 ; i <= m ; i++){
         for(int j = 1 ; j <= n ; j++){
             if(s[i-1] == t[j-1]){
                 grid[i][j] = 1 + grid[i-1][j-1];
            } else grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
         }
     }

    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1])
        {
            ans = ans + s[i-1];
            i--; j--;
        }
        else if(grid[i-1][j] > grid[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << " ";
}
