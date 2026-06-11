#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c;
    
    cin >> a >> b;
    
    if (a%2!=0 && b%2!=0)
        cout << "Yes\n";
    else 
        cout << "No\n";
    

    return 0;
}