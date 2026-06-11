#include <iostream>

using namespace std;

int main()
{
    long int a , b, sum;
    cin>>a>>b;
    sum = a*b;
    if (sum%2==0){
        cout<<"Even";
    }
    else
        cout<<"Odd";
    return 0;
}
