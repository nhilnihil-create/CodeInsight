#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int t[100000], d[100000];
vector<P> p;
vector<int> v[100000];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> t[i] >> d[i];
        t[i] --;
        p.push_back(P(d[i], t[i]));
    }
    sort(p.begin(), p.end(), greater<P>());
    int cnt = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    ll ans = 0;
    for(int i = 0; i < K; i++){
        if(v[p[i].second].size() == 0){
            cnt++;
        }else{
            que.push(p[i]);
        }
        ans += p[i].first;
        v[p[i].second].push_back(p[i].first);
    }
    ans += (ll)cnt*cnt;
    ll out = ans;
    int cur = K;
    for( ; cur < N; cur++){
        if(que.empty()) break;
        int idx = p[cur].second;
        if(v[idx].size() == 0){
            P top = que.top();
            que.pop();
            v[idx].push_back(p[cur].first); 
            cnt++;
            ans += 2*cnt-1;
            ans -= top.first;
            ans += p[cur].first;
            out = max(ans, out);
        }
    } 
    cout << out << endl;
}