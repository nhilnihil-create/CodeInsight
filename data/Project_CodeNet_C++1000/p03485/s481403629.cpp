#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1;
    cin >> num2;

    if((num1 +num2)%2 == 1)
    {
        num1++;
    }
    cout << (num1 + num2)/2 << endl;

    return 0;
}
