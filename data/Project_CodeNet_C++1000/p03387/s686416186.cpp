
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
using ll = long long ;
const int INF = 1001001001;

int main() {

    int a,b,c  ;
    cin >> a >> b >> c ; 

    if(a<b) swap(a,b) ;
    if(a<c) swap(a,c) ;
    //cout << a << b << c << endl ;
    int ans = (a-b)/2 + (a-c)/2 ;
    //cout << ans << endl ;
    int m = a ;
    int m_1 = a + 1 ;

    if(3*m%2==(a+b+c)%2)
        cout << (3*m-a-b-c)/2 << endl ;
    else
        cout << (3*(m+1)-a-b-c)/2 << endl ;
    
    return 0 ;
}