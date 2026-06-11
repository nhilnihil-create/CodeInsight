#include <bits/stdc++.h>
#define PI acos(-1)
#define falcon ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
typedef long long ll ;
using namespace std ;



int main()
{
    falcon ;

    int dp[3001][3001] , nowi , nowj ;
    vector <char> characters ;

    string s , t ;
    cin >> s >> t ;
    for(int i = 0 ; i <= s.length() ; i++)
    {
        for(int j = 0 ; j <= t.length() ; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0 ;
            else
            {
                if(s[i - 1] != t[j - 1]) dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
                else dp[i][j] = dp[i - 1][j - 1] + 1 ;
            }
        }
    }
    nowi = s.length() ;
    nowj = t.length() ;
    while(nowi > 0 && nowj > 0)
    {
        if(dp[nowi][nowj] == dp[nowi - 1][nowj]) nowi-- ;
        else if(dp[nowi][nowj] == dp[nowi][nowj - 1]) nowj-- ;
        else
        {
            characters.push_back(s[nowi - 1]) ;
            nowi-- ;
            nowj-- ;
        }
    }
    reverse(characters.begin() , characters.end()) ;
    for(int i = 0 ; i < characters.size() ; i++) cout << characters[i] ;
    cout << "\n" ;
}