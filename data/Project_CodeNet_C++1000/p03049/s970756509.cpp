#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    int output = 0;
    int a = 0;
    int b = 0;
    int both = 0;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length() - 1; j++) {
            if (s[i][j] == 'A' && s[i][j + 1] == 'B') output++;
        }
        if (s[i][0] == 'B') b++;
        if (s[i][s[i].length() - 1] == 'A') a++;
        if (s[i][0] == 'B' && s[i][s[i].length() - 1] == 'A') both++;
    }

    if (a == both && b == both && both != 0) {
        a--;
    }
    cout << output + min(a, b) << endl;

    return 0;
}
