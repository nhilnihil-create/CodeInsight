#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define INF 1000000000
#define all(x) (x).begin(), (x).end()

vector<int> dp;
vector<int> h;
int k;

int dfs(int i){
    if(i <= 0){
        return 0;
    }
    int ans;
    if(dp.at(i) != -1){
        ans = dp.at(i);
    }else{
        ans = INF;
        for(int j = 1; j <= min(k, i); j++){
            ans = min(ans, dfs(i - j) + abs(h.at(i) - h.at(i - j)));
        }
        dp.at(i) = ans;
    }
    return ans;
}

int main(){
    int n;
    cin >> n >> k;
    h = vector<int>(n);
    rep(i, n){
        cin >> h.at(i);
    }
    dp = vector<int>(n, -1);
    cout << dfs(n - 1) << endl;
}
