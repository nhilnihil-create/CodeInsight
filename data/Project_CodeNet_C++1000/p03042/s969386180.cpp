#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 50000000;
vector<int> cnt(mxN + 1);

int main() {
    string ss;
    cin >> ss;
    int f = stoi(ss.substr(0, 2)), s = stoi(ss.substr(2));
    if (ss.substr(2) == "00" && ss.substr(0, 2) == "00") {
        cout << "NA";
        return 0;
    }
    if (ss.substr(0, 2) == "00") {
        if (s <= 12) {
            cout << "YYMM";
            return 0;
        }
        else {
            cout << "NA";
            return 0;
        }
    }
    if(ss.substr(2) == "00") {
        if (f <= 12) {
            cout << "MMYY";
            return 0;
        }
        else {
            cout << "NA";
            return 0;
        }
    }
    
    if (f > 12 && s > 12) {
        cout << "NA";
        return 0;
    }
    if (f <= 12 && s <= 12) {
        cout << "AMBIGUOUS";
        return 0;
    }
    if (f <= 12) {
        cout << "MMYY";
        return 0;
    }
    if (s <= 12) {
        cout << "YYMM";
        return 0;
    }
    cout << "NA";


    return 0;
}