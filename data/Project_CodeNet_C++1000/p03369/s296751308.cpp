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
    cout << count(s.begin(), s.end(), 'o') * 100 + 700 << endl;
}
