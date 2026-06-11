#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int MAX = 110000;
int dp[MAX];

int main(){
    int n; cin >> n;
    for(int i = 0; i < MAX; ++i) dp[i] = -1;
    dp[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int pow6 = 1; v + pow6 <= n; pow6 *= 6){
            if(dp[v+pow6] == -1){
                dp[v+pow6] = dp[v] + 1;
                que.push(v+pow6);
            }
        }
        for(int pow9 = 1; v + pow9 <= n; pow9 *= 9){
            if(dp[v+pow9] == -1){
                dp[v+pow9] = dp[v] + 1;
                que.push(v+pow9);
            }
        }
    }
    cout << dp[n] << endl;
}