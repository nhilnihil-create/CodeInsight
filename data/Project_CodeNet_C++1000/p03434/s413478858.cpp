#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    int sum_Alice = 0, sum_Bob = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            sum_Alice += v[i];
        }
        else
        {
            sum_Bob += v[i];
        }
    }

    cout << sum_Alice - sum_Bob << endl;
    return 0;
}