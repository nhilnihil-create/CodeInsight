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

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    string S;
    cin >> S;
    string bb = S.substr(0, 2);
    string aa = S.substr(2, 2);
    if (bb < "13" && bb> "00") {
        if (aa < "13" && aa > "00") cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else {
        if (aa > "00" && aa < "13") cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
}
