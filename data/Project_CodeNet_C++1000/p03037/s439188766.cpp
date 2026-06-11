#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> data(M, vector<int>(2));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data.at(i).at(j);
        }
    }
    int nummin = 1;
    int nummax = 100000;
    for (int i = 0; i < M; i++) {
        nummin = max(nummin, data.at(i).at(0));
        nummax = min(nummax, data.at(i).at(1));
    }
    int ans = max(nummax - nummin + 1, 0);
    cout << ans << endl;
}
