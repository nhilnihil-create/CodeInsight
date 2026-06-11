#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926
 
int a[3];
 
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(abs(c - a) + abs(c - b), min(abs(a - b) + abs(a - c), abs(a - b) + abs(b - c)));
}