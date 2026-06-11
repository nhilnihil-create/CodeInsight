#include<iostream>
#include<map>
using namespace std;

int main() {
    int ans = 0;
    int N; cin >> N;
    map<string, int> card_counter;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        card_counter[s]++;
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        card_counter[t]--;
    }
    for (auto& x : card_counter) {
        ans = max(ans, x.second);
    }
    cout << ans << endl;
}
