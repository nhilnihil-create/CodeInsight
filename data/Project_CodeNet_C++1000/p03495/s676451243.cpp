#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    map<int, int> ma;
    vector<int> cnt(200005);//for all Ai
    rep(i,n){
        int a; cin >> a;
        cnt[a]++;
    }
    sort(RALL(cnt));
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += cnt[i];
    }
    cout << max(0, n-sum) << endl;
}