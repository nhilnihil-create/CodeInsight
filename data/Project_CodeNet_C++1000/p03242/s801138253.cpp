#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int one = n/100;
    int two = n%100/10;
    int three = n%100%10;
    if(one == 1)
    {
        cout << 9;
    }
    else if(one == 9)
    {
        cout << 1;
    }
    else
    {
        cout << one;
    }
    if(two == 1)
    {
        cout << 9;
    }
    else if(two == 9)
    {
        cout << 1;
    }
    else
    {
        cout << two;
    }if(three == 1)
    {
        cout << 9;
    }
    else if(three == 9)
    {
        cout << 1;
    }
    else
    {
        cout << three;
    }
    cout << endl;

}