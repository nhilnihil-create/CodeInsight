#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int s, ans;
    cin >> s;
    int i = 1;
    while (true) {
        if (s == 4 || s == 2 || s == 1) {
            ans = i + 3;
            break;
        }
        i++;
        if (s % 2 == 0) {
            s /= 2;
            continue;
        }
        s = 3 * s + 1;
    }
    cout << ans << endl;
}