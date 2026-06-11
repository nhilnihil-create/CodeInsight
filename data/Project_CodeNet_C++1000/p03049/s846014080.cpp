#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

uint64_t ret  = 0;
uint64_t OA   = 0;
uint64_t BO   = 0;
uint64_t BOA  = 0;

int main() {
    int N;
    cin >> N;

    string s;
    bool back_a  = false;
    bool front_b = false;
    rep(i, N) {
        cin >> s;
        back_a  = s.back()  == 'A';
        front_b = s.front() == 'B';
        if(back_a && front_b) {
            BOA++;
        }
        else if (back_a) {
            OA++;
        } else if (front_b) {
            BO++;
        }
        rep(j, s.size()-1) {
            if(s[j] == 'A' && s[j+1] == 'B') {
                ret++;
            }
        }
    }

#if 0
    cout << "OA " << OA << endl;
    cout << "BO " << BO << endl;
    cout << "BOA " << BOA << endl;
    cout << "ret " << ret << endl;
#endif

    if(OA == 0 && BO == 0) {
        if(BOA > 0)
            ret += (BOA-1);
        cout << ret << endl;
        return 0;
    }

    uint64_t tmp = 0;
    if(OA > BO) {
        tmp = OA - BO;
        ret += BO;
    } else {
        tmp = BO - OA;
        ret += OA;
    }

    ret += BOA;

    cout << ret << endl;
    return 0;
}

