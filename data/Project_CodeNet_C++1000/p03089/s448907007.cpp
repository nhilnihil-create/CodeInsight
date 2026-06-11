#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;

    cin >> num;

    vector<int> vec(num);
    vector<int> vec2;
    for (int i = 0; i < num; i++) cin >> vec.at(i),vec.at(i)--;

    for (int i = 0; i < num; i++) {
        int ans = -1;
        for (int j = vec.size() - 1; j >= 0; j--) {
            if (vec.at(j) == j) {
                ans = j;
                break;
            }
        }

        if (ans == -1) {
            cout << ans;
            return 0;
        }

        vec2.push_back(ans + 1);
        vec.erase(vec.begin() + ans);
    }

    reverse(vec2.begin(), vec2.end());
    for (int i = 0; i < vec2.size(); i++) cout << vec2.at(i) << endl;
    //
}
