#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int d;
    cin >> d;
    cout << "Christmas";
    if (d <= 24) cout << " " << "Eve";
    if (d <= 23) cout << " " << "Eve";
    if (d <= 22) cout << " " << "Eve";
    cout << endl;
}