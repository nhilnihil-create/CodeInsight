#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> ans[2000];

int s(int x){
    return x * (x - 1) / 2;
}
int f(int n){
    int sq = sqrt(n) - 5;
    sq = max(sq, 0);
    for(int i = sq ; ; i++){
        if(s(i) > n) break;
        if(s(i) == n) return i;
    }
    cout << "No" << endl;
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int k = f(n);
    int cur = 1;
    for(int i = 1 ; i <= k ; i++){
        for(int j = i + 1 ; j <= k ; j++){
            ans[i].push_back(cur);
            ans[j].push_back(cur);
            cur++;
        }
    }
    cout << "Yes" << endl << k << endl;
    for(int i = 1 ; i <= k ; i++){
        cout << ans[i].size() << " ";
        for(auto &j : ans[i]) cout << j << " ";
        cout << endl;
    }
}
