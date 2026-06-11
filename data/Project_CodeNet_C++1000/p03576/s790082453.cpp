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
    int n,k ;
    cin >> n >> k ;
    vector<pair<int64_t,int64_t> > p(n,pair<int64_t,int64_t>()) ;
    for (int i = 0; i < n; i++)
    {
        cin >> p.at(i).first >> p.at(i).second ;
    }
    int64_t ans = INT64_MAX ;
    sort(p.begin(),p.end()) ;
    for (int i = 0; i < n-k+1; i++)
    {
        vector<int64_t> y(0) ;
        for (int j = i; j < n; j++)
        {
            y.push_back(p.at(j).second) ;
            if (y.size() < k)
            {
                continue ;
            }
            int64_t xl = p.at(j).first - p.at(i).first ;
            int64_t yl = INT64_MAX ;
            sort(y.begin(),y.end()) ;
            for (int jj = 0; jj < y.size()-k+1 ; jj++)
            {
                yl = min(yl,y.at(jj+k-1) - y.at(jj)) ;
            }
            ans = min(ans,xl*yl) ;
        }
        

    }
    cout << ans << endl ;

}