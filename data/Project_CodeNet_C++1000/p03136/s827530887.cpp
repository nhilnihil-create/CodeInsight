#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    sort(all(L), greater<int>());
    int ans = 0;
    for(int i = 1; i < N; i++){
        ans += L[i];
    }
    if(ans > L[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
} 