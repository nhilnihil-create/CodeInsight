#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<int> a(n),b(n);
    priority_queue<int> que;
    ll m = 0,o = 0;
    bool flag = true;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        
    }
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            m += b[i]-a[i];
            ans++;
        }
        else if(a[i] > b[i]){
            o += a[i]-b[i];
            que.push(a[i]-b[i]);
        }
    }
    if(o < m) flag = false;
    while(!que.empty() && m > sum){
        sum += que.top(); 
        que.pop();
        ans++;
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
}