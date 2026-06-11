#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    string s = ""; cin >> s;
    if (s == "AKIHABARA" ||
        s == "KIHABARA" ||
        s == "AKIHBARA" ||
        s == "AKIHABRA" ||
        s == "AKIHABAR" ||
        s == "KIHBARA" ||
        s == "KIHABRA" ||
        s == "KIHABAR" ||
        s == "AKIHBRA" ||
        s == "AKIHBAR" ||
        s == "AKIHABR" ||
        s == "KIHBRA" ||
        s == "KIHBAR" ||
        s == "KIHABR" ||
        s == "AKIHBR" ||
        s == "KIHBR") {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    return 0;
}
 