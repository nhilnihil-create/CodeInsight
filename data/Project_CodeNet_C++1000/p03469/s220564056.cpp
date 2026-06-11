#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    vector<char> s(10);
    for (int i = 0; i < 10; i++) {
        cin >> s.at(i);
    }
    s.at(3) = '8';
    for (int i = 0; i < 10; i++) {
        cout << s.at(i);
    }
    cout << endl;
}