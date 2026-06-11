#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    for(int i=-1; i<=1; i+=2){
        for(int j=-1; j<=1; j+=2){
            for(int k=-1; k<=1; k+=2){
                priority_queue<ll> items;
                for(int a=0; a<n; a++){
                    ll scr = i * x[a] + j * y[a] + k * z[a];
                    items.push(scr);
                }
                ll tmp_ans = 0;
                for(int b=0; b<m; b++){
                    tmp_ans += items.top();
                    items.pop();
                }
                ans = max(ans, tmp_ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}