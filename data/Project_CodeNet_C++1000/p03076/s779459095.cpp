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

int d(int64_t n){
    int re = 1 ;
    while (1)
    {
        n /= 10 ;
        if (n > 0)
        {
            re ++ ;
        }else
        {
            return re ;
        }
        
        
    }
    
}

int main(){
    vector<int> t(5) ;
    for (int i = 0; i < 5; i++)
    {
        cin >> t.at(i) ;
    }
    int ans = 0 ;
    for (int i = 0; i < 5; i++)
    {
        ans += (t.at(i)/10 ) *10 ;
        t.at(i) %= 10 ;
    }
    sort(t.begin(),t.end()) ;
    bool flag = 1 ;
    for (int i = 0; i < 5; i++)
    {
        if (t.at(i) > 0)
        {
            if (flag)
            {
                ans += t.at(i) ;
                flag = 0 ;
            }else
            {
                ans += 10 ;
            }
            
            
        }
        
    }
    
    cout << ans << endl ;

}