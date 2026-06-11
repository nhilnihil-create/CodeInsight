#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int FindStart(const vector<int64_t> &vec)
{
    auto res = 0;
    for (size_t i = 0; i < vec.size(); i += 1) {
        if (abs(vec[i]) > abs(vec[res])) {
            res = i;
        }
    }
    return res;
}

vector<pair<int, int>> Solve(vector<int64_t> &vec)
{
    auto start = FindStart(vec);
    vector<pair<int, int>> moves;

    if (vec[start] > 0) {
        vec[0] += 2 * vec[start];
        moves.push_back({start, 0});
        moves.push_back({start, 0});

        for (size_t i = 1; i < vec.size(); i += 1) {
            while (vec[i] < vec[i - 1]) {
                vec[i] += vec[i - 1];
                moves.push_back({i - 1, i});
            }
        }
    } else if (vec[start] < 0) {
        vec.back() += 2 * vec[start];
        moves.push_back({start, vec.size() - 1});
        moves.push_back({start, vec.size() - 1});

        for (int i = vec.size() - 2; i >= 0; i -= 1) {
            while (vec[i] > vec[i + 1]) {
                vec[i] += vec[i + 1];
                moves.push_back({i + 1, i});
            }
        }
    }
    return moves;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int64_t> vec(n);
    for (auto &num : vec) {
        cin >> num;
    }

    auto moves = Solve(vec);
    cout << moves.size() << "\n";

    for (const auto &p : moves) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}
