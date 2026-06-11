#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> ans;
    for (int i = 1; i <= min(a, b); i++)
    {

        if (a % i == 0 && b % i == 0)
        {
            ans.push_back(i);
        }
    }
    cout << ans[ans.size() - k] << endl;
}
