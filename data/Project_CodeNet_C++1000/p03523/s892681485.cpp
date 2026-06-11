#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    vector<string> T = {"KIHBR", "AKIHBR", "KIHABR", "KIHBAR", "KIHBRA", "AKIHABR", "AKIHBAR", "AKIHBRA", "KIHABAR", "KIHABRA", "KIHBARA", "AKIHABAR", "AKIHABRA", "AKIHBARA", "KIHABARA", "AKIHABARA"};
    for (auto str : T) {
        if (S == str) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
