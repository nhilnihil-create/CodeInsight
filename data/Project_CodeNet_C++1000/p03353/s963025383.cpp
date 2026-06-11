#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int K;
    cin >> s;
    cin >> K;

    int n = s.length();

    vector<string> S;
    for (int l = 1; l <= K; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            string ss = s.substr(i, l);
            S.push_back(ss);
        }
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    cout << S[K - 1] << '\n';

    return 0;
}