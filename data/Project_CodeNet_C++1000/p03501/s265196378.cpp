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
    int a, b, c;

    cin >> a >> b >> c;

    cout << (a*b > c ? c : a*b) << endl;
}
