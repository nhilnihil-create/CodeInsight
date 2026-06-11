#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int64_t mod = 998244353 ;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


vector<int> getprime(int n){
    vector<int> p(0) ;
    vector<bool> table(n+1,0) ;
    for (int i = 2; i <= n; i++)
    {
        if (table.at(i) == 0)
        {
            p.push_back(i) ;
            for (size_t j = 2; j < n/i ; j++)
            {
                table.at(i*j) = 1 ;
            }
            
        }
        
    }
    return p ;
}

int main(){
    int n,m ;
    cin >> n >> m ;
    vector<int> menu(m,0) ;
    int k,a ;
    for (int i = 0; i < n; i++)
    {
        cin >> k ;
        for (int j = 0; j < k; j++)
        {
            cin >> a ;
            menu.at(a-1) ++ ;
        }
        
    }
    
    int ans = 0 ;
    for (int i = 0; i < m; i++)
    {
        if (menu.at(i) == n)
        {
            ans ++ ;
        }
        
    }
    
    cout << ans << endl ;
}