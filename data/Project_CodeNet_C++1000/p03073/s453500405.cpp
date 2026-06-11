#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    string s;
    cin >> s;

    int ans = 1<<29;
    for (int i = 0; i <= 1; i++) {
        int a = i;
        int count = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] - '0' != a) count++;
            a = 1 - a;
        }
        ans = min(ans, count);
    }

    cout << ans << endl;


    return 0;
}