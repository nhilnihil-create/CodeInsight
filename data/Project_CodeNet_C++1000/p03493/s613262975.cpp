#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() { 
    string s;
    cin >> s;
    int res = 0;
    for (auto ss : s) {
        if (ss == '1') res++;
    }
    cout << res << endl;
}


