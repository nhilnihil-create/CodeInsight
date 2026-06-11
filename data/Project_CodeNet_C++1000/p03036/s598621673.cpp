#include<iostream>
using namespace std;
int main()
{
    int r, d, x;
    cin >> r >> d >> x;
    int s = x;
    for(int i = 1; i <= 10; i++)
    {
        s = r * s - d;
        cout << s << " ";
    }
    return 0;
}