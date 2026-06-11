#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a ,b ,c;
    cin >> a >> b >> c;
    int d = max(a,b) ;
    int e = min(a,b) ;
    int f = max(d,c) ;
    int t = min(d,c) ;
    cout << f *10 + t + e;
    return 0;
}
