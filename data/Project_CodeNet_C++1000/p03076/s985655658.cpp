#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> food(5);
    for (int i = 0; i < 5; i++) {
        int x, r; cin >> x;
        r = x % 10;
        if (r != 0) r = 10 - r;
        food.at(i) = make_pair(r, x);
    }
    sort(food.begin(), food.end());
    int time = 0;
    for (int i = 0; i < 4; i++) {
        time += food.at(i).first + food.at(i).second;
    }
    time += food.at(4).second;
    cout << time << endl;
}