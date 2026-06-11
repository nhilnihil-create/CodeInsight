#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + k - 1 < n)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
