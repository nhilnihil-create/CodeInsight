#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n , a , b;
    cin >> n >> a >> b;

    bool can;
    if ((b - a) % 2 == 0) can = false;
    else can = true;

    if (!can) cout << "Alice" << endl;
    else cout << "Borys" << endl;
    return 0;
}