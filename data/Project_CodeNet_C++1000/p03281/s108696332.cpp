#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1 << 21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// https://atcoder.jp/contests/abc106/tasks/abc106_b

// 約数列挙
vector<int> divisor_list(int n){
    vector<int> ans;
    // 約数のペアの小さい方はi^2までにある
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            int tmp = n/i;
            ans.push_back(tmp);
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i=i+2){
        vector<int> li = divisor_list(i);
        if (li.size()==8) ans++;
    }

    cout << ans << endl;
    return 0;
}