#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>> a >>b >>c;
    if ((a>=1 && a<=500) && (b>=1 && b<=500) && (c>=1 && c<=1000))
            if (a+b>=c)
                cout<<"Yes";
            else
                cout<< "No";
    else
        cout<< "stop"


    ;return 0;
}