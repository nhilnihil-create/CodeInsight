#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n > 0)
    {
        if(n % 4 == 0 || n % 7 == 0) return cout << "Yes\n" ,0;
        else n -= 7;
    }
    cout << "No\n";
}