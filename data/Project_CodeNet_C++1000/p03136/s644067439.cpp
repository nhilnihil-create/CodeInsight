#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    int max = -1;
    int maxidx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
        if (l[i] > max)
        {
            max = l[i];
            maxidx = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < l.size(); i++)
    {
        if (i != maxidx)
        {
            sum += l[i];
        }
    }
    // cout << sum << "," << max << endl;
    if (sum > max)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
