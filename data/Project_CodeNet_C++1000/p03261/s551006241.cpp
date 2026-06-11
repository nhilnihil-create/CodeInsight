#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    string last = "";
    set<string> history;
    for (int i = 0; i < N; ++i) {
        string w;
        cin >> w;
        if (i > 0 && last.back() != w.front()) {
            cout << "No" << endl;
            return;
        }
        last = w;
        history.insert(w);
    }

    if (history.size() != N) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
