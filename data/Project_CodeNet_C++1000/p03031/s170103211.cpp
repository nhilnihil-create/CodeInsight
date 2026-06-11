#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> data(M,vector<int>(N));
    vector<int> p(M),counter(M);
    int k = 0,answer=0;
    for (int i = 0; i < M; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> data.at(i).at(j);
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p.at(i);
    }

    for (int bit = 0; bit < (1 << N); ++bit) {
        
        fill(counter.begin(), counter.end(), 0);
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) { 
                for (int j = 0; j < M; j++) {
                    auto itr = find(data.at(j).begin(), data.at(j).end(), i+1);
                    if (itr != data.at(j).end())counter.at(j)++;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (counter.at(i) % 2 != p.at(i))break;
            if (i == M-1)answer++;
        }
    }
    cout << answer << endl;
    return 0;
}