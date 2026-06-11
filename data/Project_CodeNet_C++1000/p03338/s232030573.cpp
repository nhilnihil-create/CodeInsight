#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
    int N, ans = 0; string S; cin >> N >> S;
    for (int i = 1; i < N; i++) {
        string a = S.substr(0, i), b = S.substr(i, N - i);
        set<char> counter;
        for (int j = 0; j < a.length(); j++) {
            for (int k = 0; k < b.length(); k++) {
                if (a[j] == b[k]) counter.insert(a[j]);
            }
        }
        if (ans < counter.size()) ans = counter.size();
    }
    cout << ans << endl;
}
