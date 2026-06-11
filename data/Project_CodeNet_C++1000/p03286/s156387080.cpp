#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    ll x = 1;
    rep(i,48){
        x *= 2;
    }
    ll sub_N = N + x;
    vector<ll> vec(35);
    rep(i,35){
        vec[i] = 0;
    }
    ll N_sub = 0;
    ll cnt_sub1 = 1;
    ll cnt_sub2 = 2;
    rep(i,35){
        if ((N_sub + cnt_sub1 + x) % cnt_sub2 == sub_N % cnt_sub2){
            vec[i] = 1;
            N_sub += cnt_sub1;
        }
        else{
            vec[i] = 0;
        }
        cnt_sub1 *= -2;
        cnt_sub2 *= 2;
    }
    int cnt_0 = 0;
    if (N == 0){
        cout << vec[34] << endl;
    }
    else{
        rep(i, 35){
            if (cnt_0 == 0 && vec[34 - i] == 0){
                continue;
            }
            else if (vec[34 - i] == 1){
                cnt_0++;
                cout << vec[34 - i];
            }
            else{
                cout << vec[34 - i];
            }
        }
        cout << endl;
    }
}
