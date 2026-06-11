#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    vector<pair<ll, int> > K;
    rep(i, N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    rep(i, M){
        int b; 
        ll c;
        cin >> b >> c;
        K.emplace_back(c, b);
    }
    sort(K.begin(), K.end());

    /*rep(i, M){
        cout << "K" << K[i].first << endl;
    }*/

    int count = 0;
    ll ans = 0;
    int a = N-1;
    int k = M-1;
    while(count < N){
        if(k == -1){
            ans += A[a];
            count++;
            a--;
        } else if(A[a] >= K[k].first){
            ans += A[a];
            count++;
            a--;
        } else {
            if(count + K[k].second <= N){
                ans += K[k].first * K[k].second;
                count += K[k].second;
                k--;
            } else {
                int x = N - count;
                ans += K[k].first * x;
                count += x;
                k--;
            }
        }
        //cout << "ans" << ans << endl;
    }

    cout << ans << endl;

    return 0;
}