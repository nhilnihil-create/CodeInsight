#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 1;
    rep(i, n){
        int a;
        cin >> a;


        if(a % 2 == 0) cnt *= 2;
    }

    int ans = pow(3, n) - cnt;

    cout << ans << endl;

    return 0;
}