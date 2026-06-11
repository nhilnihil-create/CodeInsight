#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int digitSum(int n){
   int res = 0;
   while(n){
       res += n % 10;
       n /= 10;
   }
   return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int> ans;
    rep(i, 1, 10) ans.push_back(i);
    ans.push_back(19);
    int last = 19;
    while(ans.size() < k){
        int now = digitSum(last);
        int add = 1;
        while((last + add) * digitSum(last + add * 2) > (last + add * 2) * digitSum(last + add)){
            add *= 10;
        }
        last += add;
        ans.push_back(last);
    }
    rep(i, 0, k){
        cout << ans[i] << endl;
    }
}