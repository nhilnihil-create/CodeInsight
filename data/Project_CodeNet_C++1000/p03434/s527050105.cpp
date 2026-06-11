#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int alice = 0, bob = 0;

    while(!a.empty()) {
        alice += a[a.size() - 1];
        a.pop_back();

        if (!a.empty()) {
            bob += a[a.size() - 1];
            a.pop_back();
        }
    }
    cout << alice - bob << endl;
}