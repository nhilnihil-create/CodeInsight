#include <bits/stdc++.h>
using namespace std;


int main(){
    long long ans = 0;
    vector<pair<long long, long long>> cans;
    long long n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cans.push_back({a,b});
    }
    sort(cans.begin(), cans.end());
    int j = 0;
    while(m > 0){
        long long am = min((long long)m, cans[j].second);
        m -= am;
        ans += am*cans[j].first;
        j++;
    }
    cout << ans << "\n";
}
