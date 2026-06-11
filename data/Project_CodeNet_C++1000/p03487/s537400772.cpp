#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (a.at(i) == a.at(j)) {
                count++;
            }
            else goto next;
        }
        next:
        if (a.at(i) < count) ans += count - a.at(i);
        else if (a.at(i) > count) ans += count;
        i += count - 1;
    }
    cout << ans << endl;
}