#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a(3);

    int k;
    cin >> a[0] >> a[1] >> a[2] >> k;
    vector<int>::iterator max = max_element(a.begin(), a.end());
    size_t index = distance(a.begin(), max);

    for (int i = 0; i < k; i++)
    {
        a[index] = a[index] * 2;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += a[i];
    }

    cout << sum << endl;
    return 0;
}
