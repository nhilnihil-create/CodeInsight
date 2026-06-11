#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long ll;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    string s;
    cin >> s;
    string zero="", one="";
    for (int i = 0; i < (int)s.size(); i++) {
        if (i % 2 == 0) {
            zero += "0";
            one += "1";
        }
        else {
            zero += "1";
            one += "0";
        }
    }
    int zerone = 0;
    int onezero = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != zero[i]) zerone++;
        if (s[i] != one[i]) onezero++;
    }
    cout << min(zerone, onezero) << endl;
}
