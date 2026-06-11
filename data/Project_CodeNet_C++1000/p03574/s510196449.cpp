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

int count(vector<vector<char> > &s, int x, int y,int h, int w){
    int re = 0 ;
    for (int i = max(x-1,0); i < min(h,x+2); i++)
    {
        for (int j = max(y-1,0); j < min(y+2,w); j++)
        {
            if (s.at(i).at(j) == '#')
            {
                re ++ ;
            }
            
        }
        
    }
    return re ;
}

int main(){
    int h,w ;
    cin >> h >> w ;
    vector<vector<char> > s(h,vector<char>(w)) ;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s.at(i).at(j) ;
        }
        
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s.at(i).at(j) == '.')
            {
                s.at(i).at(j) = '0' + count(s,i,j,h,w) ;
            }
            
        }
        
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << s.at(i).at(j) ;
        }
        cout << endl ;
    }
    
    
}