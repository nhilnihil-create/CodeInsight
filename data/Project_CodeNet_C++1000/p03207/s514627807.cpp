#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int b, d = 100, s = 0, t;
    cin >> b;
    for(int i = 0; i < b; i++)
    {
        cin >> t;
        if(d < t)
        {
            d = t;
        }
        s = s + t;
    }
    cout << s - d + d / 2;
}