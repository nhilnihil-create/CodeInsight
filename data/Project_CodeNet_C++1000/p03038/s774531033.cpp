#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    map<int, int, greater<int>> mp;
    rep(i, M){
        int b, c;
        cin >> b >> c;
        mp[c] += b;
    }
    priority_queue<int> p_que;
    for(auto p : mp){
        while(p.second != 0 && p_que.size() < N){
            p_que.push(p.first);
            p.second--;
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, N){
        if(a[i] < p_que.top() && !p_que.empty()){
            ans += p_que.top();
            p_que.pop();
        }else{
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}