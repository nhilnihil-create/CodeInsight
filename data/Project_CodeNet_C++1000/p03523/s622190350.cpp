#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    const string target = "AKIHABARA";

    bool success = true;

    int index = 0;
    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] == 'A')
        {
            if (s[index] == 'A')
            {
                index++;
            }
        }
        else
        {
            if (target[i] != s[index])
            {
                success = false;
            }
            index++;
        }
    }
    if (index != s.size())
    {
        success = false;
    }

    cout << (success ? "YES" : "NO") << endl;
}
