#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

using namespace std;

int my_abs(int num) {
    if (num > 0)
        return num;
    else
        return -num;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    string S;
    cin >> S;
    if (S.size() == 2) {
        cout << S << endl;
    }
    if (S.size() == 3) {
        char A = S.at(0);
        S.at(0) = S.at(2);
        S.at(2) = A;
        cout << S << endl;
    }
}
