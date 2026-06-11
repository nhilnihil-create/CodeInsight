#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    double ans = 0;
    cin >> n;
    vector<int> t(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        t[i] += t[i - 1];
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    v.push_back(0);
    vector<double> v2(2 * t[n] + 1);
    int ti = 1;
    for(int i = 1; i <= n; i++){
        while(ti < 2 * t[i]){
            v2[ti] = v[i];
            ti++;
        }
        v2[ti] = min(v[i], v[i + 1]);
        ti++;
    }
    for(int i = 1; i <= 2 * t[n]; i++){
        v2[i] = min(v2[i], v2[i - 1] + 0.5);
    }
    for(int i = 2 * t[n] - 1; i >= 1; i--){
        v2[i] = min(v2[i], v2[i + 1] + 0.5);
    }
    for(int i = 0; i < 2 * t[n]; i++){
        ans += 0.25 * (v2[i] + v2[i + 1]);
    }
    cout << fixed << ans << endl;
    return 0;
}
