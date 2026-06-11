#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int substract = 2 * a[2] - a[1] - a[0];
    if (substract % 2 == 0)
    {
        cout << substract / 2 << endl;
    }
    else
    {
        cout << substract / 2 + 2 << endl;
    }
}