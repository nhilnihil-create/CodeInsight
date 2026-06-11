#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll sum_a = 0;
    ll sum_b = 0;
    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum_a += a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }

    if(sum_b < sum_a){
        cout << "No" << endl;
    }
    else{
        ll cnt = sum_b - sum_a;
        ll cnt_a = 0, cnt_b = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                cnt_b += a[i]-b[i];
            }
            else if(a[i] < b[i]){
                if((b[i]-a[i])%2 == 0){
                    cnt_a += (b[i] - a[i])/2;
                }
                else{
                    cnt_a += (b[i]-a[i])/2 + 1;
                    cnt_b++;
                }
            }
        }
        if(2*(cnt-cnt_a) == cnt - cnt_b && cnt>=cnt_a && cnt >= cnt_b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}