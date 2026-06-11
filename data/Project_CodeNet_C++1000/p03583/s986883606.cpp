#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <numeric>
#include <stack>
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
    int64_t N ;
    cin >> N ;
    int64_t n,h,w ;
    n = N/4 +1 ;
    bool end = false ;
    for (int64_t i = n; i < 3500; i++)
    {
        for (int64_t j = 1; j < 3500; j++)
        {
            if (4*i*j < N*(i+j))
            {
                continue ;
            }
                
            int64_t bunbo = 4*i*j - N*j - N*i ;
            if (bunbo <= 0)
            {
                continue ;
            }
            
            int64_t bunshi = N*i*j ;

            if (bunshi % bunbo == 0 && bunshi/bunbo > 0)
            {
                w = bunshi / bunbo ;
                n = i ;
                h = j ;                
            }
            
        }
        
    }
    cout << n << " " << h << " " << w << endl  ;
}
