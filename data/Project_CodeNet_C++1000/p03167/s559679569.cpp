#include <bits/stdc++.h>
#define PI acos(-1)
#define falcon ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
typedef long long ll ;
using namespace std ;

char grid[1001][1001] ;
int paths[1001][1001] ;

int main()
{
    falcon ;

    int n , m ;
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> grid[i][j] ;
            paths[i][j] = 0 ;
        }
    }
    paths[0][0] = 1 ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[i][j] == '#') continue ;
            if(i > 0) paths[i][j] = paths[i][j] + paths[i - 1][j] ;
            if(j > 0) paths[i][j] = paths[i][j] + paths[i][j - 1] ;
            paths[i][j] = paths[i][j] % 1000000007 ;
        }
    }
    cout << paths[n - 1][m - 1] << "\n" ;
}