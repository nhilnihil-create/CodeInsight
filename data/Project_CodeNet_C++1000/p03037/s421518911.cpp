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
    int n,m ;
    cin >> n >> m ;
    int mi = 1 ;
    int M = n;
    int l,r ;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r ;
        mi = max(mi,l) ;
        M = min(M,r) ;
    }
    
    cout << max(M-mi+1,0) << endl;
    
    
}
