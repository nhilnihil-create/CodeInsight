#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool result = false;
    int d_i = 0, c_i = 0;
    while (7 * d_i <= N) {
        if ((N - 7*d_i) % 4 == 0) {
            result = true;
            break;
        }
        else
        {
            d_i++;
        }
    }
    if (result) {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}