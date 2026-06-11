#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for(int i = 0;i < a.size() - 8;i++)
    {
        cout << a[i];
    }
    return 0;
}