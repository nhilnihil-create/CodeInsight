#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return b.second < a.second;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> red(N);
    for (int i = 0; i < N; i++)
        cin >> red[i].first>>red[i].second;

    vector<pair<int, int>> blue(N);
    for (int i = 0; i < N; i++)
        cin >> blue[i].first >> blue[i].second;

    sort(red.begin(), red.end(),cmp);
    sort(blue.begin(), blue.end());

    int ans = 0;
    vector<bool> red_used(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (red_used[j]) continue;
            if (blue[i].first > red[j].first&& blue[i].second > red[j].second) {
                ans++;
                red_used[j] = true;
                break;
            }
        }
    }

    cout << ans << endl;
}
