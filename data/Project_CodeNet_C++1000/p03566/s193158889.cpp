#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> acc(n+1, 0);
    for (int i = 0; i < n; i++) acc[i+1] = acc[i] + t[i];
    vector<vector<float>> lmt(n+2, vector<float>(acc.back()*2 + 1));
    for (int i = 0; i < acc.back()*2 + 1; i++){
        lmt[0][i] = 1.0f * i / 2;
        lmt[n+1][i] = 1.0f * (acc.back()*2 - i) / 2;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < acc.back()*2 + 1; j++){
            if (1.0f * j / 2 < acc[i-1]) lmt[i][j] = v[i-1] + (acc[i-1] - 1.0f * j / 2);
            else if (1.0f * j / 2 > acc[i]) lmt[i][j] = v[i-1] + (1.0f * j / 2 - acc[i]);
            else lmt[i][j] = v[i-1];
        }
    }

    float ans = 0;
    for (int i = 0; i < acc.back()*2 + 1; i++){
        float min_v = 200;
        for (int j = 0; j < n+2; j++) min_v = min(min_v, lmt[j][i]);
        ans += min_v * 2;
    }
    cout << setprecision(10) << ans / 4 << endl;
}