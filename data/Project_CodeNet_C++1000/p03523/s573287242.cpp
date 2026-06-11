#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> v;
    v.insert("KIHBR");
    v.insert("AKIHBR");
    v.insert("KIHABR");
    v.insert("KIHBAR");
    v.insert("KIHBRA");
    v.insert("AKIHABR");
    v.insert("AKIHBAR");
    v.insert("AKIHBRA");
    v.insert("KIHABAR");
    v.insert("KIHABRA");
    v.insert("KIHBARA");
    v.insert("AKIHABAR");
    v.insert("AKIHABRA");
    v.insert("AKIHBARA");
    v.insert("KIHABARA");
    v.insert("AKIHABARA");

    cout << (v.count(s) == 1 ? "YES" : "NO") << endl;
}
