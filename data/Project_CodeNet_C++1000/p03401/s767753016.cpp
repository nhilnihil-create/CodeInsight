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
#include<map>
#include<set>
using namespace std;

int main() {
    int n, a[100000] = {}, l = 0;
    cin >> n;
    a[0] = a[n + 1] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    for (int i = 0; i <= n; i++) {
        l += abs(a[i + 1] - a[i]);
    }
    for (int i = 1; i <= n;i++) {
        cout << l - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i - 1]) << endl;
    }
}
