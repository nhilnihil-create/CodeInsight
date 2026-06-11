#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>
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
    vector<bool> c(1000001,0) ;
    int s ;
    cin >> s ;
    int ans = 1 ;
    c.at(s) = 1 ;
    while (1)
    {
        if (s % 2 == 0)
        {
            s /= 2 ;
        }else
        {
            s = 3*s + 1 ;
        }
        ans ++ ;
        if (c.at(s) == 1)
        {
            break ;
        }else
        {
            c.at(s) = 1 ;
        }
        
        
        
    }
    
    cout << ans << endl ;
    
}