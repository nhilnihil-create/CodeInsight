#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> indices;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'W')
        {
            indices.push_back(i);
        }
    }
    long long ans = 0;
    int cnt = 0;
    for (int index : indices)
    {
        ans += index - cnt;
        ++cnt;
    }
    cout << ans << endl;
    return 0;
}
