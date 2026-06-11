#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[300000] {0};
    for(int i = 0; i < (1 << n); i++) cin >> a[i];
    int fir[300000];
    int sec[300000];
    bool looked[300000];
    for(int i = 0; i < (1 << n); i++) fir[i] = i;
    fill(sec, sec + n, (1 << n));
    fill(looked, looked + n, false);
    queue<int> que;
    fir[0] = 0;
    looked[0] = true;
    que.push(0);
    while(que.size()){
        int now = que.front();
        que.pop();
        for(int i = 0; i < n; i++){
            int next = (now | (1 << i));
            if(next == now) continue;
            if(!looked[next]){
                looked[next] = true;
                que.push(next);
            }
            if(fir[now] == fir[next]){
                if(a[sec[next]] < a[sec[now]]) sec[next] = sec[now];
            }
            else if(a[fir[next]] < a[fir[now]]){
                if(a[fir[next]] < a[sec[now]]) sec[next] = sec[now], fir[next] = fir[now];
                else sec[next] = fir[next], fir[next] = fir[now];
            }
            else{
                if(a[sec[next]] < a[fir[now]]) sec[next] = fir[now];
            }
        }
    }
    for(int k = 1; k < (1 << n); k++){
        int ans = a[fir[k]] + a[sec[k]];
        int now = 0;
        for(int i = n - 1; i >= 0; i--){
            if(k & (1 << i)){
                ans = max(ans, a[fir[now + (1 << i) - 1]] + a[sec[now + (1 << i) - 1]]);
                now |= (1 << i);
            }
        }
        cout << ans << endl;
    }
}