#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <complex>
#include <map>

#define forin(i, f, t) for(ll i = f; i < t; i++)

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    int evens[8] = {2,10,3,9,4,8,6,12};
    int odds[8] = {6,2,10,3,9,4,8,12};
    
    if (n == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
    } else if (n % 2 == 0) {
        for (auto i = 0; i < n; i++)
            cout << evens[i % 8] + (i / 8) * 12 << " ";
    } else {
        for (auto i = 0; i < n; i++)
            cout << odds[i % 8] + (i / 8) * 12 << " ";
    }
    
}

