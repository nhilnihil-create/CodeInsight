#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;


int main() {
    int N, P;
    string S;
    cin >> N;
    psi p1;
    pair<psi, int> p;
    vector<pair<psi, int>> data(N);
    for (int i = 0; i < N; i++) {
        cin >> S >> P;
        p1 = make_pair(S, P * -1);
        p = make_pair(p1, i + 1);
        data.at(i) = p;
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < N; i++) {
        cout << data.at(i).second << endl;
    }
}