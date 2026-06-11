#include <iostream>

using namespace std;

int main()
{
    int num1,num2,num3,num4;
    cin >>num1>>num2>>num4;
    num3 = num1 * num2;
    if (num3 >= num4)
        cout << num4;
    else cout << num3;

    return 0;
}
