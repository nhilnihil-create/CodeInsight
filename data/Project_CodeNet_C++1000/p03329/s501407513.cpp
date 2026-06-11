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
    int n ;
    cin >> n ;
    int ans = n ;
    int temp,s,t ;
    for (int i = 0; i < n+1; i++)
    {
        temp = 0 ;
        s = i ;
        t = n-i ;
        while(s > 0 || t > 0){
            temp += (s%6 + t%9) ;
            s /= 6 ;
            t /= 9 ;
        }
        ans = min(ans,temp) ;
    }
    cout << ans << endl ;
}