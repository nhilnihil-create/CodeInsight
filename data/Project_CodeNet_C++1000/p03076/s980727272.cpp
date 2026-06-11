#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    vector<int> time(5);
    vector<int> time_10(5);
    for(int i = 0; i < 5; i++){
        cin >> time[i];
        int tmp = time[i]%10;
        if(tmp) time_10[i] = time[i] + (10 - tmp);
        else time_10[i] = time[i];
    }
    int ans = INF;
    for(int i = 0; i < 5; i++){
        int cnt = 0;
        for(int j = 0; j < 5; j++){
            if(j == i) cnt += time[j];
            else cnt += time_10[j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}