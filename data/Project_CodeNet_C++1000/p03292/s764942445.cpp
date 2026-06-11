#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    int min = *min_element(a.begin(), a.end());
    int max = *max_element(a.begin(), a.end());

    cout << abs(min - max) << endl;

    return 0;
}
