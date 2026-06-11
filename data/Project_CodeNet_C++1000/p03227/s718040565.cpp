#include <iostream> 
#include <cstdio> 
#include <cstdlib>  
#include <algorithm> 
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <tuple>
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
    if (s.size() == 2) cout << s << endl;
    else {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}
