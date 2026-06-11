#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    rep(i, N)cin >> v[i];
    ll ans = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; i + j <= K; j++){
            priority_queue<ll, vector<ll>, greater<ll> > queue;
            queue.push(0);
            int lindex = 0, rindex = N - 1;
            ll sum = 0;
            // cout << i << j<<endl;
            for(lindex; lindex < i; lindex++){
                if(lindex >= N - 1){
                    lindex = N - 1;
                    break;
                }
                sum += v[lindex];
                queue.push(v[lindex]);
            }
            // cout << "i: " << i << " j: " << j << endl;
            // cout << lindex << " " << rindex << endl;
            // cout << sum << endl;
            for(rindex; rindex > N - j - 1; rindex--){
                sum += v[rindex];
                queue.push(v[rindex]);
                if(rindex == lindex)break;
            }
            
            for(int n = 0; n < K - i - j; n++){
                if(queue.top() < 0){
                    sum -= queue.top();
                    queue.pop();
                }else break;
            }
            // cout << "i: " << i << " j: " << j << " sum: " <<sum<<endl;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}