#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    char c;
    cin >> c;
    if (c == 'A') cout << 'T';
    else if (c == 'C') cout << 'G';
    else if (c == 'G') cout << 'C';
    else cout << 'A';
}
