#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    int loss = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'x')loss++;
    }
    if (loss >= 8)cout << "NO";
    else cout << "YES";
}