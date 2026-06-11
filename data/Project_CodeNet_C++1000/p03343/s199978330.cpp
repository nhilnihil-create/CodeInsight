#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
int mod = 1000000007;
int INF = 1000000009;
ll INFL = 1000000000000000018ll;

int N, K, Q, a[2020], b[2020];

signed main()
{
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int ans = INFL;
    sort(b, b + N);
    for(int i = 0; i < N; i++){
        priority_queue<int, vector<int>, greater<int> > que, suzuki;
        for(int j = 0; j < N; j++){
            if(b[i] <= a[j]){
                que.push(a[j]);
            }
            else {
                while(que.size() >= K){
                    suzuki.push(que.top());
                    que.pop();
                }
                while(que.size() > 0){
                    que.pop();
                }
            }
        }
        while(que.size() >= K){
            suzuki.push(que.top());
            que.pop();
        }
        if(suzuki.size() < Q){
            continue;
        }
        int mn = suzuki.top();
        for(int j = 0; j < Q - 1; j++){
            suzuki.pop();
        }
        int mx = suzuki.top();
        if(mx < mn)return 1;
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;


    return 0;
}
