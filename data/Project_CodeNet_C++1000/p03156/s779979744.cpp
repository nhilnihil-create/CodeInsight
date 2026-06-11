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
    int n;
    cin >> n;
    array<int, 3> counter{};
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        const auto index = (p <= a ? 0 : p <= b ? 1 : 2);
        counter[index]++;
    }
    cout << *min_element(counter.begin(), counter.end()) << endl;
}
