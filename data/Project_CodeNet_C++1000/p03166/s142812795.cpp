#include <bits/stdc++.h>
#define PI acos(-1)
#define falcon ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
typedef long long ll ;
using namespace std ;

vector <int> g[100001] , d(100001 , -1) ;
int maxlength = INT_MIN ;

void DFS(int s)
{
    d[s] = 0 ;
    for(int i = 0 ; i < g[s].size() ; i++)
    {
        int n = g[s][i] , length = 0 ;
        if(d[n] == -1) DFS(n) ;
        length = 1 + d[n] ;
        d[s] = max(d[s] , length) ;
    }
    maxlength = max(maxlength , d[s]) ;
}

int main()
{
    falcon ;

    int n , m ;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
    }
    for(int i = 1 ; i <= n ; i++) DFS(i) ;
    cout << maxlength << "\n" ;
}