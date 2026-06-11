#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    ll left = 0;
    ll right = 0;
    ll xor_cnt = 0;
    ll sum_cnt = 0;
    ll ans = 0;
    xor_cnt = vec[0];
    sum_cnt = vec[0];
    while(right < N){
        if (right == N - 1){
            if (xor_cnt == sum_cnt){
                ans += (right - left + 1);
                right++;
            }
            else{
                xor_cnt = (xor_cnt ^ vec[left]);
                sum_cnt = (sum_cnt - vec[left]);
                left++;
            }
        }
        else if (xor_cnt == sum_cnt){
            ans += (right - left + 1);
            right++;
            xor_cnt = (xor_cnt ^ vec[right]);
            sum_cnt = sum_cnt + vec[right];
        }
        else{
            xor_cnt = (xor_cnt ^ vec[left]);
            sum_cnt = (sum_cnt - vec[left]);
            left++;
        }
    }
    cout << ans << endl;
}