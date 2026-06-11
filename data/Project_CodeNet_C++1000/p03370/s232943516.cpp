#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> m;
    int sum = 0;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m.push_back(a);
        sum += a;
    }
    int cnt = 0;
    x -= sum;
    cnt += n;

    int min = *min_element(m.begin(), m.end());
    // cout << min << endl;
    while (x >= min)
    {
        x -= min;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
