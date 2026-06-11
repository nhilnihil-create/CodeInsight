#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

constexpr ll INF = 1000000000;/* 1e+9a */

void solve(istream &cin) {
    ll N;
    if (!(cin >> N)) { return; }
    vector<int> cost(N, INF);
    deque<int> np;
    cost[1] = 1;
    np.push_back(1);
    while(!np.empty()){
        int c = np.front();
        np.pop_front();
        int nextc = c + 1;
        nextc %= N;

        if(cost[nextc] > cost[c] + 1){
            cost[nextc] = cost[c] + 1;
            np.push_back(nextc);
        }
        nextc = 10 * c;
        nextc %= N;
        if(cost[nextc] > cost[c]) {
            cost[nextc] = cost[c];
            np.push_front(nextc);
        }
    }
    cout << cost[0] << endl;
}

int main(int argc, char *argv[]) {
    string FileName("D"), Modifier("MEPH_");
    string ExecutionName = Modifier + FileName;
    string sub(argv[0]);
    // /home/USER/.../MEPH_X -> MEPH_X
    if (sub.size() > ExecutionName.size())
        sub = sub.substr(sub.size() - ExecutionName.size(), ExecutionName.size());

    cout << setprecision(16) << scientific;
    if (sub != ExecutionName) {
        cin.tie(0);
        ios::sync_with_stdio(false);
        while (cin) { solve(cin); }
    } else {
        cerr << sub << " test" << endl;
        string inFile = FileName + ".txt";
        auto fs = fstream(inFile, fstream::in);
        while (fs) { solve(fs); }
    }
}
