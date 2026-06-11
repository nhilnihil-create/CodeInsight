#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    
    vector<int> cnt(1000010, 0);
    cnt[n]++;
    int v = INF;
    int index = 1;
    while(cnt[n] != 2){
        if(n%2 == 0) n /= 2;
        else n = 3 * n + 1;

        if(v > n){
            v = min(v, n);
        }
        cnt[n]++;
        index++;
    }
    cout << index << endl;
    return 0;
}