#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    map<int, int> count_map;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++count_map[a];
    }

    int ans = 0;
    for (pair<int, int> element : count_map) {
        if (element.first > element.second) {
            ans += element.second;
        }
        if (element.first < element.second) {
            ans += element.second - element.first;
        }
    }

    cout << ans << endl;

    return 0;
}