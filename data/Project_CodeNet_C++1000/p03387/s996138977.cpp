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
    
    int a, b, c;
    cin >> a >> b >> c;
    int abc = a + b + c;
    int max_abc = max(a, max(b, c)) * 3;
    if ((max_abc - abc) % 2 == 0) {
        cout << (max_abc - abc) / 2 << endl;
    } else {
        cout << (max_abc - abc + 3) / 2 << endl;
    }
}


