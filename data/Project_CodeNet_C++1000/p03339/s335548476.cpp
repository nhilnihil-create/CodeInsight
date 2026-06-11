#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 0;
    string s;

    cin >> n;
    cin >> s;

    // Counting west gorup
    int* westGroupCount = new int[n];
    int* eastGroupCount = new int[n];
    for(int i = 0; i < n; i++)
    {
        westGroupCount[i] = 0;
        eastGroupCount[i] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        westGroupCount[i] = westGroupCount[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
    }

    // Counting east group
    for(int i = n - 2; i >= 0; i--)
    {
        eastGroupCount[i] = eastGroupCount[i + 1] + (s[i + 1] == 'E' ? 1 : 0);
    }

    int minCount = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int count = westGroupCount[i] + eastGroupCount[i];
        if(count < minCount)
        {
            minCount = count;
        }
    }

    cout << minCount;

    return 0;
}
