#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int n, ans;
VI abc, l;

const int INF = 1<<20;

int f(int x, VI lup, VI ldown){
    int cost = INF;
    int lusz = lup.size(), ldsz = ldown.size();
    rep(i, lusz){
        cost = min(cost, lup[i] - x);
    }
    for(int i = 1; i < (1<<ldsz); i++){
        VI used(ldsz);
        rep(j, ldsz) if (i>>j & 1) used[j] = 1;
        int len = 0;
        int merge = 0;
        rep(j, ldsz){
            if (used[j] == 0) continue;
            if (len != 0) merge += 10;
            len += ldown[j];
            cost = min(cost, abs(len - x) + merge);
        }
    }
    return cost;
}

void dfs(VI nums){
    if ((int)nums.size() == n){
        VI cnts(3);
        for(int j = 0; j < n; j++){
            cnts[nums[j]]++;
        }
        if (cnts[0] == 0 || cnts[1] == 0 || cnts[2] == 0) return;

        int sum = 0;
        for(int j = 0; j < 3; j++){
            int x = abc[j];
            VI lup, ldown;
            for(int k = 0; k < n; k++){
                if (nums[k] == j) {
                    if (l[k] >= x) lup.push_back(l[k]);
                    else ldown.push_back(l[k]);
                }
            }
            sum += f(x, lup, ldown);
        }
        ans = min(ans, sum);
    }else{
        for(int j = 0; j < 3; j++){
            nums.push_back(j);
            dfs(nums);
            nums.pop_back();
        }
    }
}

int main(){
    cin >> n;
    abc.resize(3);
    l.resize(n);
    rep(i,3) cin >> abc[i];
    rep(i,n) cin >> l[i];
    ans = INF;
    dfs(VI(0));
    cout << ans << endl;
    return 0;
}