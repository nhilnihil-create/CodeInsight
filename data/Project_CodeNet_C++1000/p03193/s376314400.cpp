#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int main()
{
    int n, w, h;
    cin >> n >> h >> w;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= h && b >= w)
            count++;
    }
    cout << count << endl;
    return 0;
}
