#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
      
    string N;
    cin >> N;

    if (N.at(0) == N.at(1) && N.at(1) == N.at(2)) {

        cout << "Yes" << endl;

    }

    else if (N.at(1) == N.at(2) && N.at(2) == N.at(3)) {

        cout << "Yes" << endl;

    }

    else {
        cout << "No" << endl;
    }

}
