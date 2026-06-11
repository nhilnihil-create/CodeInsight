#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

bool is_month(int num) {
    bool ans = false;
    if(1 <= num && num <= 12) {
        ans = true;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;

    int inputnum = stoi(s);
    int first = inputnum / 100;
    int second = inputnum % 100;
    string ans;

    if(is_month(first) && is_month(second)) {
        ans = "AMBIGUOUS";
    } else if(is_month(first)) {
        ans = "MMYY";
    } else if(is_month(second)) {
        ans = "YYMM";
    } else {
        ans = "NA";
    }

    cout << ans << endl;
}