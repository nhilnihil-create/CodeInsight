#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>

using namespace std;


int main() {
    int N;
    cin >> N;
    string stone;
    cin >> stone;

    vector<pair<int, int>> bw_cnt(N);
    for (int i = 1; i < N; i++) {
        bw_cnt[i].first = bw_cnt[i - 1].first;
        if (stone[i - 1] == '#')
            bw_cnt[i].first++;
    }
    for (int i = N-1; i >= 0; i--) {
        if (i == N - 1) {
            if (stone[i] == '.')
                bw_cnt[i].second++;
        }
        else {
            bw_cnt[i].second = bw_cnt[i + 1].second;
            if (stone[i] == '.')
                bw_cnt[i].second++;
        }
    }
    int ans = bw_cnt[N-1].first;
    if (stone[N - 1] == '#') ans++;
    
    for (int i = 0; i < N; i++) {
        int temp = bw_cnt[i].first + bw_cnt[i].second;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
