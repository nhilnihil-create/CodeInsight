#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

int main(){
    int n,m ;
    cin >> n >> m ;
    vector<int> a(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    a.at(0) %= m ;
    for (size_t i = 0; i < n-1; i++)
    {
        a.at(i+1) += a.at(i) ;
        a.at(i+1) %= m ;
    }
    map<int,int64_t> mod ;
    mod[0] ++ ;
    vector<int> num(1,0) ;
    for (size_t i = 0; i < n; i++)
    {
        mod[a.at(i)] ++ ;
        if (mod[a.at(i)] == 1)
        {
            num.push_back(a.at(i)) ;
        }
        
    }
    int64_t ans = 0 ;
    for (size_t i = 0; i < num.size(); i++)
    {
        ans += mod[num.at(i)] * (mod[num.at(i)] -1) /2 ;
    }
    cout << ans << endl ;
}
