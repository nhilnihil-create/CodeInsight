#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;


int main() {
    cin >> N >> M;
    vector<pair<int, int>> requests(M);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        requests.at(i).first = b; 
        requests.at(i).second = a;
    }

    sort(requests.begin(), requests.end());
    int answer = 0;
    int current = 0;

    for (int i = 0; i < M; i++) {
        if (current <= requests.at(i).second) {
            answer++;
            current = requests.at(i).first;
        }
    }

    cout << answer << endl;
    return 0;
}