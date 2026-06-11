#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;

int main(void){
    int N, M;
    cin >> N >> M;
    // vector<ll> A(N);
    priority_queue<long long, vector<long long>, greater<long long>> A;
    vector<pair<ll, ll>> vp(M);
    for (int i=0; i<N; i++){
        ll a; cin >> a;
        A.push(a);
    }
    for (int i=0; i<M; i++){
        ll b, c;
        cin >> b >> c;
        vp.emplace_back(c, b);
    }
    sort(vp.rbegin(), vp.rend());
    
    int change_num = 0;
    for (int i=0; i<M;i++){
        ll b = vp[i].second;
        ll c = vp[i].first;
        
        for (int j=0; j<b; j++){
            ll a = A.top();
            if(a < c){
                change_num++;
                A.pop();
                A.push(c);
            }else{
                ll ans = 0;
                while(!A.empty()){
                    ans += A.top();
                    A.pop();
                }
                cout << ans << endl;
                return 0;
            }
            if(change_num >= N){
                ll ans = 0;
                while(!A.empty()){
                    ans += A.top();
                    A.pop();
                }
                cout << ans << endl;
                return 0;
            }
        }
    }
    ll ans = 0;
    while(!A.empty()){
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
}
