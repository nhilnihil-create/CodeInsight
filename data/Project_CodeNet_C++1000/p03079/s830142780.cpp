#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int a, b, c;
    cin >> a >> b >> c;

    if (a==b && b==c) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}