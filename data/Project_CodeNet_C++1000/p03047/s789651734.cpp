#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "iomanip"

using namespace std;

#include <cstdio>
#include <cstring>


int main() {
    int n, m, count = 0, res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n ; ++i) {
        count++;
        if (count == m){
            res++;
            count = 0;
            i -= (m - 1);
        }
    }
    cout << res;

}