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
    vector<int> x(4,0) ;
    vector<int> y(4,0) ;
    int dx,dy ;
    cin >> x.at(0) >> y.at(0) >> x.at(1) >> y.at(1) ;
    dx = x.at(1) - x.at(0) ;
    dy = y.at(1) - y.at(0) ;
    swap(dx,dy) ;
    dx *= -1 ;
    x.at(2) = x.at(1) + dx ;
    y.at(2) = y.at(1) + dy ;
    swap(dx,dy) ;
    dx *= -1 ;
    x.at(3) = x.at(2) + dx ;
    y.at(3) = y.at(2) + dy ;
    cout << x.at(2) << " " << y.at(2) << " " << x.at(3) << " " << y.at(3) << endl ;
}
