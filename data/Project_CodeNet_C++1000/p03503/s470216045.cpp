#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> shop = vector<vector<int>>(100, vector<int>(10, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> shop[i][j];
        }
    }
    vector<vector<int>> gain = vector<vector<int>>(100, vector<int>(11, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            cin >> gain[i][j];
        }
    }
    vector<int> map = vector<int>(1024, 0);
    
    for (int i = 0; i < 1024; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int count = 0;
            for (int k = 0; k < 10; ++k)
            {
                int num = ((i >> k) & 1);
                if (num & shop[j][k])
                {
                    count++;
                }
            }
            map[i] += gain[j][count];
        }
    }
    int ret = -2147483648;
    for (int i = 1; i < 1024; ++i)
    {
        ret = max(ret, map[i]);
    }
    cout << ret << endl;

    return 0;
}
