#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    vector<int> sub(N);
    vector<ll> sub_sum(N+1, 0);
    rep(i, N) sub[i] = A[i] - B[i];
    sort(sub.begin(), sub.end(), greater<int>());
    for(int i = 1; i < N+1; i++){
        sub_sum[i] = (ll)sub_sum[i-1] + sub[i-1];
    }
    ll lack_sum = 0;
    ll margin = 0;
    int ans = 0;
    rep(i, N){
        if(A[i] < B[i]){
            lack_sum += (ll)B[i] - A[i];
            ans++;
        }else{
            margin += (A[i] - B[i]);
        }
    }
    if(margin < lack_sum){
        cout << -1 << endl;
        return 0;
    }
    rep(i, N+1){
        if(lack_sum <= sub_sum[i]){
            ans += i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}