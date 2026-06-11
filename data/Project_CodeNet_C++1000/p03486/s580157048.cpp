#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define print(x) cout << x << "\n";

int main()
{
    string s, t;
    cin >> s >> t;

    sort(all(s));
    sort(all(t), greater<char>());

    string ans = t > s?"Yes":"No";

    cout << ans << endl;

}