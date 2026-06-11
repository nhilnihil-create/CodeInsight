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
    int d;
    cin >> d;
    string res = "Christmas";
    d -= 25;
    while (d < 0) {
    	res += " Eve";
    	d++;
    }
    cout << res << endl;
}
