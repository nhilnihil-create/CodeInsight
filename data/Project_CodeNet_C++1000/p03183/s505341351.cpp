#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18+5

vector<int> w(1009);
vector<int> s(1009);
vector<int> v(1009);

vector< int > dp(20009);

bool comp(int a, int b){
    return s[a] + w[a] > s[b] + w[b];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> elements(n);

    for(int i = 0; i < n; i++){
        elements[i] = i;
        cin >> w[i] >> s[i] >> v[i];
    }

    sort(elements.begin(), elements.end(), comp);

    for(int j = 0; j < n; j++){

        int i = elements[j];

        for(int k = w[i]; k < 20009; k++){

            dp[min(k-w[i],s[i])] = max(dp[min(k-w[i], s[i])], dp[k]+v[i]);

        }
    }

    int ans = 0;

    for(int i = 0; i < 10009; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
