#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    string copy = s;
    reverse(all(s));
    if (s == copy) {
        cout << 0 << endl;
        return 0;
    }

    string remove_x = "";
    rep(i, s.size()) {
        if (copy[i] == 'x')
            continue;
        else
            remove_x += copy[i];
    }
    string remove_copy = remove_x;
    reverse(all(remove_x));
    if (remove_copy != remove_x) {
        cout << -1 << endl;
        return 0;
    }

    int left = 0, right = copy.size() - 1, res = 0;
    while (right - left > 0) {
        if (copy[left] == 'x' && copy[right] != 'x')
            left++, res++;
        if (copy[left] != 'x' && copy[right] == 'x')
            right--, res++;
        if (copy[left] == copy[right])
            left++, right--;
    }

    cout << res << endl;
    return 0;
}