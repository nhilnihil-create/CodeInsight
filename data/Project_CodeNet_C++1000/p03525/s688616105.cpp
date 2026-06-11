#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <functional>
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

int solve(vector<bool> clock){
    int ans = 24 ;
    int temp = 1 ;
    for (int i = 1; i < 24; i++)
    {
        if (clock.at(i) == 1)
        {
            ans = min(ans,temp) ;
            temp = 1 ;
        }else
        {
            temp ++ ;
        }
        
    }
    ans = min(ans,temp) ;
    return ans ;
}

int main(){
    int n ;
    cin >> n ;
    vector<int> t(13,0) ;
    int d ;
    for (int i = 0; i < n; i++)
    {
        cin >> d ;
        t.at(d) ++ ;
    }
    if (t.at(0) > 0 || t.at(12) > 1)
    {
        cout << 0 << endl ;
        return 0 ;
    }
    for (int i = 1; i < 12; i++)
    {
        if (t.at(i) > 2)
        {
            cout << 0 << endl ;
            return 0 ;
        }
        
    }
    vector<bool> clock(24,0) ;
    vector<int> choice(0) ;
    clock.at(0) = 1 ;
    for (int i = 1; i < 12; i++)
    {
        if (t.at(i) == 1)
        {
            choice.push_back(i) ;
        }else if (t.at(i) == 2)
        {
            clock.at(i) = 1 ;
            clock.at(24-i) = 1 ;
        }
        
        
    }
    if (t.at(12) == 1)
    {
        clock.at(12) = 1 ;
    }
    int ans = 0 ;
    for (int bit = 0; bit < pow(2,choice.size()) - 0.1; bit++)
    {
        for (int i = 0; i < choice.size(); i++)
        {
            if (bit &(1 << i))
            {
                clock.at(24 - choice.at(i)) = 1 ;
            }else
            {
                clock.at(choice.at(i)) = 1 ;
            }
            
            
        }
        ans = max(ans,solve(clock)) ;
        for (size_t i = 0; i < choice.size(); i++)
        {
            clock.at(choice.at(i)) = 0 ;
            clock.at(24 - choice.at(i)) = 0 ;
        }
        
        
    }
    cout << ans << endl ;
    
}