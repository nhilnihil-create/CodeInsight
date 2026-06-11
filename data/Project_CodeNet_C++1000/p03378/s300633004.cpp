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
    int n,m,x,a ;
    cin >> n >> m >> x ;
    int r = 0 ;
    int l = 0 ;
    for (size_t i = 0; i < m; i++)
    {
        cin >> a ;
        if (a < x)
        {
            l ++ ;
        }else
        {
            r ++ ;
        }
        
        
    }
    cout << min(l,r) << endl ;
    
}