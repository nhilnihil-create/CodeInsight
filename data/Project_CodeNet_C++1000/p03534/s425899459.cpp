#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto t : s) {
        if (t == 'a') a++;
        else if (t == 'b') b++;
        else c++;
    }
    int mx = max({a, b, c});
    bool ch = (mx - a <= 1 && mx - b <= 1 && mx - c <= 1);
    cout << (ch ? "YES" : "NO") << endl;
    return 0;
}