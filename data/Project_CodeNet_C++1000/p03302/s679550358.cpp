#include <bits/stdc++.h>
using namespace std;
int a;
int b;
int main()
{
    cin >> a >> b;
    int n = a+b;
    int m = a*b;
    if (n == 15&&m != 15)   cout << "+" << endl;
    if (n != 15&&m == 15)   cout << "*" << endl;
    if (n != 15&&m != 15)   cout << "x" << endl;
    return 0;
}