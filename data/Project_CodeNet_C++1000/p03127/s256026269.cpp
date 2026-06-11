#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int f(int a, int b)
{
    if (a < b)
        std::swap(a, b);
    while (b > 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> b;
        a = f(a, b);
    }
    cout << a << endl;
    return 0;
}
