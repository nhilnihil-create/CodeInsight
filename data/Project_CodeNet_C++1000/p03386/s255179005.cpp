#include <iostream>
using namespace std;
int main()
{
    int a, b, c; cin >> a >> b >> c;
    if (b-a+1<=c*2)
    {
        for (int i = 0; i <= b - a; ++i)
        {
            cout << i + a<<"\n";
        }
    }
    else
    {
        for (int i = 0; i < c; ++i)
        {
            cout << a + i << "\n";
        }
        for (int i = 0; i < c; ++i)
        {
            cout << b - c + i + 1<<"\n";
        }
    }
   
    return 0;
}
