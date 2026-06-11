#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int num[1000] = {};
    int a, b, c;

    cin >> a >> b >> c;
    num[a+100]++; num[b+100]++; num[c+100]++;

    for (int i = 0; i <= 200; i++) {
        if (num[i] == 1) {
            cout << i-100 << endl;
        }
    }
}
