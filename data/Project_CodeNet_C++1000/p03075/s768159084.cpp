#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    vector<int> niz(5);
    int k;
    for (int i = 0; i < 5; i++)
        cin >> niz[i];
    cin >> k;
    for (int i = 0; i < 5 - 1; i++)
        for (int j = i + 1; j < 5; j++)
        {
            if (niz[j] - niz[i] > k)
            {
                cout << ":(";
                return 0;
            }
        }
    cout << "Yay!";
}