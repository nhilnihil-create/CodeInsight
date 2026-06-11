#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue<int, vector<int>, greater<int>> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push(tmp);
    }
    map<int, int, greater<int>> C;
    for (int i = 0; i < M; i++) {
        int b, c;
        cin >> b >> c;
        C[c] += b;
    }

    for (auto c : C) {
        // cout << c.first << " " << c.second << endl;
        for (int i = 0; i < c.second; i++) {
            if (A.top() < c.first) {
                A.pop();
                A.push(c.first);
            } else {
                break;
            }
        }
    }

    ll output = 0;
    for (int i = 0; i < N; i++) {
        output += (ll)A.top();
        A.pop();
        // cout << A[i] << endl;
    }
    cout << output << endl;

    return 0;
}
