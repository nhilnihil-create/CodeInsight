#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    long long H = 0 , W = 0 , MOD = 1000000007 ;
    cin >> H >> W ;
    char grid[H+1][W+1] ;
    long long ways[H+1][W+1] ;
    for(long long i = 1 ; i <= H ; i++)
        for(long long j = 1 ; j <= W ; j++)
            cin >> grid[i][j] , ways[i][j] = 0 ;
    for(long long i = 1 ; i <= H ; i++){
        if(grid[i][1] == '#') break ;
        ways[i][1] = 1 ;
    }
    for(long long i = 1 ; i <= W ; i++){
        if(grid[1][i] == '#') break ;
        ways[1][i] = 1 ;
    }
    for(long long i = 2 ; i <= H ; i++)
        for(long long j = 2 ; j <= W ; j++)
            if(grid[i][j] != '#')
                ways[i][j] = (ways[i-1][j] % MOD + ways[i][j-1] % MOD) % MOD ;
    cout << ways[H][W] ;
}