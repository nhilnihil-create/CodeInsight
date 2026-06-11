#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m, sum = 0;
    cin >> n >> m;
    vector<vector<long long>> v = vector<vector<long long>>(n, vector<long long>(2));
    for (int i = 0; i < n; i++) {
        cin >> v.at(i).at(0) >> v.at(i).at(1);
    }
    sort(v.begin(), v.end(), [](const vector<long long>& a, const vector<long long>& b) { return a[0] < b[0]; });
    int i = 0;
    while (i < n) {
        if (m < v.at(i).at(1)) {
            sum += m * v.at(i).at(0);
            break;
        }
        m -= v.at(i).at(1);
        sum += v.at(i).at(0) * v.at(i).at(1);
        i++;
    }
    cout << sum << endl;
    return 0;
}