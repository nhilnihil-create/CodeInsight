#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
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
    int n ;
    cin >> n  ;
    vector<vector<int64_t> > p(n,vector<int64_t> (3)) ;
    int64_t a,b ;
    for (size_t i = 0; i < n; i++)
    {
       cin >> a >> b ;
       p.at(i).at(0) = -1*(a+b) ;
       p.at(i).at(1) = a ;
       p.at(i).at(2) = b ;

    }
    sort(p.begin(),p.end()) ;
    int64_t ans = 0 ;
    for (size_t i = 0; i < n; i+= 2)
    {
        ans += p.at(i).at(1) ;
    }for (size_t i = 1; i < n; i+= 2)
    {
        ans -= p.at(i).at(2) ;
    }
    cout << ans << endl ;
}