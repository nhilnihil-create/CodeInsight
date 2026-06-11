#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> stacks;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        stacks.insert(x);
    }
    cout << stacks.size();
}