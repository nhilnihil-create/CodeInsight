#include<iostream>
#include<deque>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAX_K = 1e5 + 1;

bool is_checked[MAX_K];

int main() {
    int K;
    cin >> K;
    deque<P> DQ;
    DQ.push_back(P(1, 1));
    while (!DQ.empty()) {
        P now = DQ.front();
        DQ.pop_front();
        int num = now.first, cost = now.second;
        if (is_checked[num]) continue;
        is_checked[num] = true;
        if (num == 0) {
            cout << cost << endl;
            return 0;
        }
        DQ.push_back(P(((num + 1) % K), cost + 1));
        DQ.push_front(P(((num * 10) % K), cost));
    }
    return 0;
}