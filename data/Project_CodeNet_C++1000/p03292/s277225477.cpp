#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int m = max({ a,b,c });
    int n = min({ a,b,c });
    cout << m - n << endl;
}

