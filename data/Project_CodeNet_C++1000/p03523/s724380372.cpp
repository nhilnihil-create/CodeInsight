#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    if (s == "AKIHABARA" || s == "KIHABARA" || s == "AKIHBARA" || s == "AKIHABRA" || s == "AKIHABAR" ||
        s == "KIHBARA" || s == "KIHABRA" || s == "KIHABAR" || s == "AKIHBRA" || s == "AKIHBAR" || s == "AKIHABR" ||
        s == "KIHBRA" || s == "KIHBAR" || s == "KIHABR" || s == "AKIHBR" || s == "KIHBR") {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}