#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> divide(long long n){//素因数分解
    map<long long, long long> res;
    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
int main(){
    int N;
    cin >> N;
    map<long long, long long> m;
    for(int i = 2; i <= N; i++){
        map<long long, long long> t = divide(i);
        for(auto v: t){
            m[v.first] += v.second;
        }
    }
    vector<int> cnt(10000);
    for(auto v: m){
        if(v.second >= 74) cnt[75]++;
        if(v.second >= 24) cnt[25]++;
        if(v.second >= 14) cnt[15]++;
        if(v.second >= 4) cnt[5]++;
        if(v.second >= 2) cnt[3]++;
    }
    int ans = 0;
    ans += cnt[25] * (cnt[3] - 1) + cnt[15] * (cnt[5] - 1) + cnt[5] * (cnt[5] - 1) * (cnt[3] - 2) / 2 + cnt[75];
    cout << ans << endl;
}