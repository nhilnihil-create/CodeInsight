#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <math.h>
#include <functional>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
int main(){
    vector<int> a(3);
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    str s = to_string(a[2]) + to_string(a[1]);
    int s2 = stoi(s);
    cout << s2 + a[0] << endl;
    return 0;
}