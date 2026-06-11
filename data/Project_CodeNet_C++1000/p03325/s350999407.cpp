#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    uint32_t N;
    cin >> N;
    uint32_t ai;
    uint32_t ans(0);
    for (size_t i = 0; i < N; ++i)
    {
        cin >> ai;
        while (ai != 0)
        {
            if (ai % 2 != 0)
            {
                break;
            }
            ans++;
            ai = ai / 2;
        }
    }
    cout << ans << endl;
    return 0;
}