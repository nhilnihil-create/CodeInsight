#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <chrono>

using namespace std;

int main() {
    //ifstream cin("input.in");
    string s, t;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' || s[i] == 'C') {
            t.push_back(s[i]);
        } else if (i < n - 1 && s[i + 1] == 'C') {
            t.push_back('X');
            i++;
        } else {
            t.push_back('B');
        }
    }
    long long answer = 0;
    int length = 0;
    for (int i = t.size() - 1; i >= 0; i--) {
        if (t[i] == 'A') {
            answer += length;
        } else if (t[i] == 'X') {
            length += 1;
        } else {
            length = 0;
        }
    }
    cout << answer << "\n";
    return 0;
}





