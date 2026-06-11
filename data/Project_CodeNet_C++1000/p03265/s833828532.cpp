#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x2 - x1;
    int b = y2 - y1;
    int ansx, ansy;
    ansx = x2 - b;
    ansy = y2 + a;
    cout << ansx << ' '<< ansy << ' ';
    ansx -= a;
    ansy -= b;
    cout << ansx << ' ' << ansy << endl;
}