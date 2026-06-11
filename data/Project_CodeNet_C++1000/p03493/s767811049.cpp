#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "111";
    string b = "";
    int c;
    cin >> b;

    string intersection;
    set_intersection(begin(a), end(a), begin(b), end(b), back_inserter(intersection));
    c = intersection.size();

    cout << c << endl;
}