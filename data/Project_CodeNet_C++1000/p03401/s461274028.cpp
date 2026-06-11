#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, ai, s = 0;
    vector<int> a, d;
    cin >> n;

    a.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> ai;
        a.push_back(ai);
        d.push_back(abs(a[i + 1] - a[i]));
        s += d[i];
    }
    a.push_back(0);
    d.push_back(abs(a[n + 1] - a[n]));
    s += d[n];

    for(int i = 0; i < n; i++){
        cout << s - (d[i] + d[i + 1]) + abs(a[i + 2] - a[i]) << endl;
    }
    return 0;
}