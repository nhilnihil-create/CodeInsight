#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int maxn = 1e5 + 10;

stack<bool> s;

string a;

int main() {
    int ans = 0;
    cin >> a;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (s.empty()) s.push(a[i] - '0');
        else if (a[i] - '0' != s.top()) {
            s.pop();
            ans += 2;
        }
        else s.push(a[i] - '0');
    }
    cout << ans;
    return 0;
}