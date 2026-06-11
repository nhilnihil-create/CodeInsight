#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <numeric>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
    int n ;
    cin >> n ;
    vector<int64_t> a(n) ;
    vector<int64_t> b(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b.at(i) ;
    }
    vector<int64_t> c(n) ;
    for (size_t i = 0; i < n; i++)
    {
        c.at(i) = a.at(i) - b.at(i) ;
    }
    sort(c.begin(),c.end()) ;
    bool ans = false ;
    if (c.at(n-1) < 1)
    {
        ans = true ;
    }else
    {
        int i = 0 ;
        int j = n-1 ;
        while(1){
            if (c.at(j) < 1)
            {
                ans = true ;
                break ;
            }else if (c.at(i) > -2)
            {
                ans = false ;
                break ;
            }
            int64_t judge = c.at(i) + c.at(j)*2 ;
            if ( judge <= 0 )
            {
                c.at(i) = judge ;
                if (c.at(i) > -2)
                {
                    i ++ ;
                }
                j -- ;
            }else
            {
                int p = c.at(i)/-2 ;
                c.at(j) -= p ;
                c.at(i) += 2*p ;
                i ++ ;
            }
            
            
            
        }
    }
    
    if (ans == true)
    {
        cout << "Yes" << endl ;
    }else
    {
        cout << "No" << endl ;
    }
    
    
}
