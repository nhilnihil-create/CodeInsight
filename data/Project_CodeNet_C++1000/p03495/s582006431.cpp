// Not so Diverse
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> boll(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        boll[x-1]++;
    }
    int count = 0;
    sort(boll.begin(), boll.end());
    reverse(boll.begin(), boll.end());

    for (int i = K; i < N; i++) count += boll[i];

    cout << count << endl;
}