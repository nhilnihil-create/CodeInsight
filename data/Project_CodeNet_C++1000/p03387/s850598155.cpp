#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    vector<int> V(3);
    cin >> V[0] >> V[1] >> V[2];

    sort(V.begin(), V.end());
    int count = 0;
    count += V[2] - V[1];
    V[1] += count; V[0] += count;

    if((V[2] - V[0]) % 2 == 0 ) count += (V[2] - V[0]) / 2;
    else count += (V[2] - V[0]) / 2 + 2;
    cout << count << endl;
}