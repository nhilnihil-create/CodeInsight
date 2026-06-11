#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>
#include <iomanip>

using namespace std;

int main(){

    int T, X;
    cin >> T >> X;
    double ans = (double)T / X;

    cout << setprecision(8) << ans << endl;

    return 0;
}