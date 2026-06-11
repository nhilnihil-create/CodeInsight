#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a , b , c , d , e , k , _max , _min , dif ;
    cin >> a >> b >> c >> d >> e >> k ;
    _max = max(max(max(a,b),max(c,d)),e) ;
    _min = min(min(min(a,b),min(c,d)),e) ;
    dif = _max - _min ;
    if (dif <= k){
        cout << "Yay!" ;
    }
    else {
        cout << ":(" ;
    }
    return 0;
}
