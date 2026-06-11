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
int n;
void dfs(vector<int> &ve, int &ans, int ind, int now){
    if(ind >= n) return;
    if(now == 1){
        ans++;
        return;
    }
    if(ve[ind] >= 74 && now % 75 == 0) dfs(ve, ans, ind + 1, now / 75);
    if(ve[ind] >= 24 && now % 25 == 0) dfs(ve, ans, ind + 1, now / 25);
    if(ve[ind] >= 14 && now % 15 == 0) dfs(ve, ans, ind + 1, now / 15);
    if(ve[ind] >= 4 && now % 5 == 0) dfs(ve, ans, ind + 1, now / 5);
    if(ve[ind] >= 2 && now % 3 == 0) dfs(ve, ans, ind + 1, now / 3);
    dfs(ve, ans, ind + 1, now);
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
    n = (int)m.size();
    vector<int> vec(n);
    int ind = 0;
    for(auto v: m){
        vec[ind] = v.second;
        ind++;
    }
    int ans = 0;
    dfs(vec, ans, 0, 75);
    cout << ans << endl;
}