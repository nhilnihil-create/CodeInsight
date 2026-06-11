#include<bits/stdc++.h>
using namespace std;
int main() 
{
    long long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long sum;
    if(a + b > 2 * c)
    {
        sum = min(x,y) * 2 * c;
        if(abs(x - y) * (x > y ? a : b) > abs(x - y) * 2 * c)
        {
            cout << max(x,y) * 2 * c << endl;
        }
        else
        {
            cout << sum + abs(x - y) * (x > y ? a : b) << endl;
        }
        
    }
    else
    {
        cout << a * x + b * y << endl; 
    }
}