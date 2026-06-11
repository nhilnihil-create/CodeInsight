#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    long long x, y;
    cin >> x >> y;
    
    int count = 0;
    while(x <= y) {
        count ++;
        x *= 2;
    }
    cout << count << endl;
    return 0;
}