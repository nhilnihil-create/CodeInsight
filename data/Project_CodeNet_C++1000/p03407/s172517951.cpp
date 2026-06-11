#include <bits/stdc++.h>
using namespace std;
int a;
int b;
int n;
int main()
{
    cin >> a >> b >> n;
    int m = a+b;
    if (m >= n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    } 
    return 0;
}