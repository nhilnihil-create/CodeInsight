#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;

int n;
vector<vector<int>>ans;

void dfs(vector<int> A) {
    if (A.size() == n + 1) {
        ans.push_back(A);
        return;
    }

    A.push_back(0);
    while (A.back() <= 3) {
        dfs(A);
        A.back()++;
    }
}

int main() {
    
    vector<int>t(3);
    cin >> n;
    rep(i, 3)cin >> t[i];
    vector<int>l(n);
    rep(i, n)cin >> l[i];
    dfs(vector<int>(1, 0));
    int res = INF;
    rep(i, 1 << (2 * n)) {
        vector<int>now = ans[i];
        vector<int>abc(3);
        int sum = 0;
        arep(j, 1, n + 1) {
            if (now[j] == 3)continue;
            abc[now[j]] += l[j - 1];
            sum += 10;
        }
        if (abc[0] == 0 || abc[1] == 0 || abc[2] == 0)continue;
        sum -= 30;
        int a = abs(t[0] - abc[0]);
        int b = abs(t[1] - abc[1]);
        int c = abs(t[2] - abc[2]);

        res = min(res, sum+a + b + c);
    }
    cout << res << endl;


    return 0;
}