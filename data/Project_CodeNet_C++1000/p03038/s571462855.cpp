#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N,M;
    cin >>N >>M;
    priority_queue<P> pq;
    for(int i=0;i<N;i++){
        ll A;
        cin >> A;
        pq.push(P(A,1));
    }
    for(int i=0;i<M;i++){
        ll B,C;
        cin >> B >>C;
        pq.push(P(C,B));
    }
    ll ans =0;
    for(int i=0;i<N;i++){
        P p =pq.top();pq.pop();
        ans += p.first;
         p.second--;
        if(p.second>0){
            pq.push(p);
        }
    }
    cout << ans << endl;
    return 0;
}