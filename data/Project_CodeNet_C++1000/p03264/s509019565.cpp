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
    int a;

    cin >> a;

    if (a%2) {
        cout << (a/2+1) * (a/2) << endl;
    }
    else {
        cout << (a/2) * (a/2) << endl;
    }
}
