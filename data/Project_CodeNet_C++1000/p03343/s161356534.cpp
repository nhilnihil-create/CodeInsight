#include <bits/stdc++.h>
using namespace std;

int main() {
   // ifstream cin("data.in");
    int n, k, q;
    cin >> n >> k >> q;
    vector<int>val(n);
    for(int i = 0; i < n; ++i)
        cin >> val[i];
    int answer = 1e9;
    for(int pos_min = 0; pos_min < n; ++pos_min) {
        int minn = val[pos_min];
        vector<int>avaible;
        for(int i = 0; i < n; ) {
            int j = i;
            vector<int>cur;
            while(j < n && val[j] >= minn) {
                cur.push_back(val[j]);
                j++;
            }
            sort(cur.begin(), cur.end());
            for(int t = 0; t + k - 1 < (int)cur.size(); ++t)
                avaible.push_back(cur[t]);

            i = j + 1;
        }
        sort(avaible.begin(), avaible.end());
        if((int)avaible.size() >= q) {
            answer = min(answer, avaible[q - 1] - minn);
        }
    }
    cout << answer;
    return 0;
}
