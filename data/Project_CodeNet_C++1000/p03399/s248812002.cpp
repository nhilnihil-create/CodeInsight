#include <iostream>
 
using namespace std;
 
int main()
{
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    int bus = min(a , b);
    int train = min (c , d);
    cout << bus + train;
    return 0;
}