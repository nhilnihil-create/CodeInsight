//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
const int N = (1 << 18) + 10;
int arr[N];
pair<int, pair<int, int>> memo[N];

int main() {
   // freopen("in.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); ++i) {
        scanf("%d", arr + i);
        memo[i] = {arr[i], {arr[i], 0}};
    }
    for (int i = 0; i < n; ++i) {
        for (int msk = 0; msk < (1 << n); ++msk) {
            if (msk & (1 << i)) {
                vector<int> vec;
                vec.push_back(memo[msk].second.first);
                vec.push_back(memo[msk].second.second);

                vec.push_back(memo[msk ^ (1 << i)].second.first);
                vec.push_back(memo[msk ^ (1 << i)].second.second);
                sort(vec.rbegin(), vec.rend());
                pair<int, pair<int, int>> p = {vec[0] + vec[1], {vec[0], vec[1]}};
                memo[msk] = max(memo[msk], p);
            }
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (i > 1) memo[i].first = max(memo[i].first, memo[i - 1].first);
        printf("%d\n",memo[i].first);
    }
}