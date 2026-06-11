#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int a = v[n - 1];

    double mid = a / 2.0;
    
    int b = v[0];
    double minD = abs(mid - b);

    for(int i = 1; i < n - 1; ++i) {
        double d = abs(mid - v[i]);

        if(minD > d) {
            minD = d;
            b = v[i];
        }
    }

    cout << a << " " << b << endl;

    return 0;
}