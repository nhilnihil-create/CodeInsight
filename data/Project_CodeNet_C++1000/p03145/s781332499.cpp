#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c;
    int area;
    
    cin >> a >> b >> c;
    
    if (a>b && a>c) area = (b*c)/2;
    else if (b>a && b>c) area = (a*c)/2;
    else area = (a*b)/2;
    
    cout << area << endl; 

    return 0;
}