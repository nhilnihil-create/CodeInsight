#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,k;
    
    cin >> a >> b >> c;
    cin >> k;
    max({a,b,c});
    
    
    
    int sum = a+b+c;
    
    cout << sum + max({a,b,c})* ((1 << k) - 1);
    

    return 0;
}