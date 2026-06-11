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



int main(){
    string s ;
    cin >> s ;
    bool end = false ;
    string a = "a" ;
    a.at(0) -= 1 ;
    string p = a ;
    while(end == 0){
        int i = 0 ;
        while (1)
        {
            if (p.at(0) == 'z')
            {
                break ;
            }
            bool ok = true ;
            p.at(0) = p.at(0) + 1 ;
            for (size_t j = 0; j < s.size() ; j++)
            {
                
                if (p.at(0) == s.at(j))
                {
                    ok = false ;
                    break ;
                }
                
            }
            if (ok == true)
            {
                cout << s+p << endl ;
                return 0 ;
            }
            
            i ++ ;
        }
        if (s.size() == 0)
        {
            cout << "-1" << endl ;
            return 0 ;
        }else
        {
            p = s.at(s.size()-1) ;
            s.pop_back() ;
        }
        
        
        
    }
    
}
