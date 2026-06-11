#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a,b;
    cin >> a >> b;
    int i;
    int x,y,z,u,v;
    int count = 0;
    for(i = a ; i <= b ; i++ )
    {
        x = i / 10000;
        y = (i % 10000) / 1000;
        z = (i % 1000) / 100;
        u = ( i % 100) / 10;
        v = i % 10;
        if(i == 10000 * v + 1000 * u + 100 * z + 10 * y + x)
        {
            count++;
        }
    }
    cout << count << endl;
}
