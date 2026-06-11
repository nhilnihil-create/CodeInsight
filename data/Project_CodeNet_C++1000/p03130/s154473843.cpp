#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int num[5] = {};

    for (int i = 0; i < 3; i++) {
        int a, b;

        cin >> a >> b;
        num[a]++;
        num[b]++;
    }

    for (int i = 1; i < 5; i++) {
        if (num[i] == 3) {
            cout << "NO" << endl;
            return (0);
        }
    }
    cout << "YES" << endl;
}
