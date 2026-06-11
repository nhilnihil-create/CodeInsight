#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;

int main(void) {
    int N;
    string S;
    cin >> N >> S;
    // BWBBW -> WWBBB
    int numW = 0;
    int numB = 0;
    for(auto c: S) {
        if(c == '.') {
            numW++;
        } else {
            numB++;
        }
    }
    int seenW = 0;
    int seenB = 0;
    int ret = seenB + numW;
    for(auto c: S) {
        if(c == '.') {
            seenW++;
            numW--;
        } else {
            seenB++;
            numB--;
        }
        ret = min(ret, seenB + numW);
    }
    cout << ret << endl;
    return 0;
}
