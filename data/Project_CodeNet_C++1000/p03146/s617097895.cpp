#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s;
    cin >> s;

    int i = 1;
    vector<int> a;
    a.push_back(s);
    while (1)
    {
        if (a[i - 1] % 2 == 0)
        {
            a.push_back(a[i - 1] / 2);
        }
        else
        {
            a.push_back(3 * a[i - 1] + 1);
        }
        // cout << "i:" << i << "," << a[i] << endl;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
        i++;
    }
    return 0;
}