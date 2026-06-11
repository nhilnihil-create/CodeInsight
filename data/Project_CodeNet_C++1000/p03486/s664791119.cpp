#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm/reverse.hpp>
using namespace std;
int main() {
    string S, T; cin >> S >> T;
    boost::sort(S);
    boost::sort(T); boost::reverse(T);
    if (S < T) cout << "Yes" << endl;
    else cout << "No" << endl;
}
