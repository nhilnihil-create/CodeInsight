#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

ll N, M, ans=0, tmp=0, a, b, c;
vector<ll> A;
priority_queue<pair<ll, ll>> Q;

signed main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<M;i++) {
        cin >> b >> c;
        Q.push(make_pair(c, b));
    }
    while(!Q.empty()) {
        if(tmp==N) break;
        pair<ll, ll> p = Q.top();
        Q.pop();
        for(int i=0;i<p.second;i++) {
            if(tmp==N) break;
            else A.push_back(p.first);
            tmp++;
        }
    }
    sort(A.begin(), A.end());
    //cout << "OK" << endl;
    for(int i=A.size()-1;i>=A.size()-N;i--) {
        ans += A[i];
        //cout << A[i] << endl;
    }
    cout << ans << endl;
    return 0;
}