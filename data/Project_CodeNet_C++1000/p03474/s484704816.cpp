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
    int a,b ;
    string s ;
    cin >> a >> b >> s ;
    bool ans = 1 ;
    int c ;
    for (int i = 0; i < a ; i++)
    {
        c = s.at(i) - '0' ;
        if (0 > c || 9 < c )
        {
            ans = 0 ;
        }
        
    }
    if (s.at(a) != '-')
    {
        ans = 0 ;
    }
    for (int i = 0; i < b; i++)
    {
        c = s.at(a+b-i) - '0' ;
        if (0 > c || 9 < c )
        {
            ans = 0 ;
        }
    }
    if (ans == 1)
    {
        cout << "Yes" << endl ;
    }else
    {
        cout << "No" << endl ;
    }
    
    
}
