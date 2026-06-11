#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; i++){
        cin >> v.at(i);
    }

    ll res = 0;
    ll right = 0;     
    ll sum = 0;
    for (ll left = 0; left < N; ++left) {
        while (right < N && (sum + v[right] == (ll)(sum^v[right]))){
            /* 実際に right を 1 進める */
            sum+= v[right];
            ++right;
        }
        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);
        res += right - left;

        /* left をインクリメントする準備 */
        // ex: if (right == left) ++right;
        // ex: else sum -= a[left];
        if(right == left){
            ++right;
        } else { 
            sum -= v[left];
        }
    }
    cout << res << endl;

}