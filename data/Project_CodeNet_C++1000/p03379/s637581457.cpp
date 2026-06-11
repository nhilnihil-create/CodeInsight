#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
vector<int> vis(N);
void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> store;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        store[a[i]].push_back(i);
    }
    sort(a, a + n);
    vector<int> ans(n);
    map<int, int> idx;
    for(int i = 0; i < n / 2; i++){
        ans[store[a[i]][idx[a[i]]++]] = a[n / 2];
    }
    for(int i = n / 2; i < n; i++){
        ans[store[a[i]][idx[a[i]]++]] = a[n / 2 - 1];
    }
    for(int &i : ans){
        cout << i << '\n';
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}