#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <queue>
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
    int a,b,c,x ;
    cin >> a >> b >> c >> x ;
    int ans = 0 ;

    for (int i = 0; i < a+1; i++)
    {
        for (int j = 0; j < b+1; j++)
        {
            for (int k = 0; k < c+1; k++)
            {
                if (500*i + 100*j + 50*k == x)
                {
                    ans ++ ;
                }
                
            }
            
        }
        
    }
    

    cout << ans << endl;
    
    
}
