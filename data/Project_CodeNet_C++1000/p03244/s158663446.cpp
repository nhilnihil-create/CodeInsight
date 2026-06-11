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

constexpr int kMOD = 1000000007;

int main() {
    int N;
    cin >> N;
    map<int, uint64_t> oddFreq;
    map<int, uint64_t> evenFreq;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        if(i%2) {
            evenFreq[tmp]++;
        } else {
            oddFreq[tmp]++;
        }
    }

    // sort by freq
    vector<pair<uint64_t, int>> vodd; 
    vector<pair<uint64_t, int>> veven; 
    for(auto itr: oddFreq) {
        vodd.push_back({itr.second, itr.first});
    }
    for(auto itr: evenFreq) {
        veven.push_back({itr.second, itr.first});
    }
    sort(vodd.rbegin(), vodd.rend());
    sort(veven.rbegin(), veven.rend());

#if 0
    for(auto itr: veven) {
        cout << "(" << itr.first << "," << itr.second << ")" << endl; 
    }
#endif


    uint64_t Nodd  = N / 2;
    uint64_t Neven = N / 2;

    if(vodd[0].second != veven[0].second) {
        Nodd  -= vodd[0].first;
        Neven -= veven[0].first;
    } else {
        // all same
        if(vodd.size() == 1 && veven.size() == 1) {
            Nodd = 0;
        }
        else if (vodd.size() == 1) {
            Nodd  -= vodd[0].first;
            Neven -= veven[1].first;
        } else if (veven.size() == 1) {
            Nodd  -= vodd[1].first;
            Neven -= veven[0].first;
        } else if (vodd[1] > veven[1]) {
            Nodd  -= vodd[1].first;
            Neven -= veven[0].first;
        } else {
            Nodd  -= vodd[0].first;
            Neven -= veven[1].first;
        }
    }
    cout << Nodd + Neven << endl;
    return 0;
}

