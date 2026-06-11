#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
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
    int n;
    cin >> n;

    vector<int> niz(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
        sum += niz[i];
    }
    int max = *max_element(niz.begin(), niz.end());
    sum -= max;
    if (max < sum)
        cout << "Yes";
    else cout << "No";
}