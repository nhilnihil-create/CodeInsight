#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    int v[N];
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i <= min(N, K); i++)
    {
        for (int j = 0; i + j <= min(N, K); j++)
        {
            vector<int> jewelry;
            for(int k = 0; k < i; k++) jewelry.push_back(v[k]);
            for(int k = 0; k < j; k++) jewelry.push_back(v[N-1-k]);

            sort(jewelry.begin(), jewelry.end());
            int s = 0;
            for (int k = 0; k < min(K - i - j, (int)jewelry.size()); k++)
            {
                if(jewelry[k] < 0) s++;
            }
            int tmp = 0;
            for (int k = s; k < jewelry.size(); k++)
            {
                tmp += jewelry[k];
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}