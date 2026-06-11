#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n, k;
    cin >> n >> k;
    P p[100005];
    for(int i = 0; i < n; i++){
        int t;
        ll d;
        cin >> t >> d;
        t--;
        p[i] = P(d, t);
    }
    sort(p, p + n, greater<P>());
    bool b[100005]{0};
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll s = 0;
    ll c = 0;
    for(int i = 0; i < k; i++){
        if(b[p[i].second]){
            que.push(p[i].first);
        }
        else{
            b[p[i].second] = true;
            c++;
        }
        s += p[i].first;
    }
    ll ans = s + c * c;
    for(int i = k; i < n; i++){
        if(que.empty()) break;
        if(b[p[i].second]) continue;
        b[p[i].second] = true;
        s -= que.top();
        que.pop();
        s += p[i].first;
        c++;
        ans = max(ans, s + c * c);
    }
    cout << ans << endl;
}
