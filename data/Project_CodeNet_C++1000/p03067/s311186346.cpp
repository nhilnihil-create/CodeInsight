#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

int main(){
    string ans;
    int a,b,c ;
    cin >> a >> b >> c ;
    if (a > b)
    {
        if (a > c && c > b)
        {
            ans = "Yes" ;
        }else
        {
            ans ="No" ;
        }
        
        
    }else
    {
        if (b > c && c > a)
        {
            ans = "Yes" ;
        }else
        {
            ans = "No" ;
        }
        
        
    }
    cout << ans << endl ;
     

}