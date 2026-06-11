#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int &i : a){
            cin >> i;
        }
        for(int &i : b){
            cin >> i;
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                cnt1 += a[i] - b[i];
            }else{
                cnt2 += (b[i] - a[i]) / 2;
            }
        }
        if(cnt1 > cnt2){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
}