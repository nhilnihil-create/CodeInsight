#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod = 1e9+9;
const int INF = 1e9;

int main(){
    int n, k;
    cin >> n >> k;

    int array[n];
    rep(i,n) cin >> array[i];

    int ans = INF;
    int index;
    rep(i,n-k+1){
        index = array[i+k-1] - array[i];
        index += min(abs(array[i+k-1]), abs(array[i]));
        ans = min(ans, index);
    }
    cout << ans << endl;
    return 0;
}
