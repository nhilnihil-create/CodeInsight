#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = -INF;
    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= n; j++){
            if(i + j > n) continue;
            int cnt = j + i;
            if(cnt > k) continue;
            int sum = 0;
            priority_queue<int, vector<int>, greater<int>> que;
            for(int l = 0; l < i; l++){
                que.push(v[l]);
                sum += v[l];
            }
            for(int r = n-1; r >= n - j; r--){
                que.push(v[r]);
                sum += v[r];
            }
            while(!que.empty() && cnt < k){
                int tmp = que.top(); que.pop();
                if(tmp < 0){
                    sum -= tmp;
                    cnt++;
                }
                else break;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
