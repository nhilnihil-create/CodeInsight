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
    int n,x ;
    cin >> n >> x ;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    int ans = 0;
    sort(a.begin(),a.end()) ;
    for (int i = 0; i < n; i++)
    {
        x -= a.at(i) ;
        if (x >= 0)
        {
            ans ++ ;
        }else
        {

            break;
        }
        
        
    }
    if (x > 0)
    {
        ans -- ;
    }
    
    cout << ans << endl ;
}