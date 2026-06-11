#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define INF 1000000
#define all(x) (x).begin(), (x).end()

vector<int> dp;
vector<int> h;

int dfs(int i){
    if(i == 0){
        return 0;
    }
    int ans;
    if(dp.at(i) != -1){
        ans = dp.at(i);
    }else if(i - 2 < 0){
        ans = dfs(i - 1) + abs(h.at(i) - h.at(i - 1));
        dp.at(i) = ans;
    }else{
        ans = min(dfs(i - 1) + abs(h.at(i) - h.at(i - 1)), dfs(i - 2) + abs(h.at(i) - h.at(i - 2)));
        dp.at(i) = ans;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    h = vector<int>(n);
    rep(i, n){
        cin >> h.at(i);
    }
    dp = vector<int>(n, -1);
    cout << dfs(n - 1) << endl;
}
