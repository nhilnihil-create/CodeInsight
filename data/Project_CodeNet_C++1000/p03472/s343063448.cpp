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
    int n,h ;
    cin >> n >> h ;
    vector<pair<int,int> > s(n,pair<int,int>()) ;
    for (int i = 0; i < n; i++)
    {
        cin >> s.at(i).first >> s.at(i).second ;
    }
    sort(s.begin(),s.end()) ;
    pair<int,int> keep = s.at(n-1) ;
    s.pop_back() ;
    for (int i = 0; i < n-1; i++)
    {
        swap(s.at(i).first, s.at(i).second) ;
    }
    sort(s.begin(),s.end(),greater<pair<int,int> >()) ;
    int ans = 0 ;
    bool end = 0 ;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i).first > keep.first)
        {
            h -= s.at(i).first ;
            ans ++ ;
            if (h <= 0)
            {
                end = 1 ;
                break ;
            }else if (h <= keep.second)
            {
                h -= keep.second ;
                ans ++ ;
                end = 1 ;
                break ;
            }
            
        }else
        {
            break ;
        }
        
        
        
        
        
    }
    if (end == 0)
    {
        h -= keep.second ;
        ans ++ ;
        ans += (h+keep.first-1)/keep.first ;
    }
    cout << ans << endl ;
    
}