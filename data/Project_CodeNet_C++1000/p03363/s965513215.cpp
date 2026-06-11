#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    ll sum[n + 1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i] = 0;
    }
    sum[n] = 0;

    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + a[i];
    }

    sort(sum, sum + n + 1);

    ll ans = 0;
    ll cou = 0;
    for(int i = 0; i < n; i++){
        if(sum[i] == sum[i + 1]){
            cou++;
        }else{
            if(cou != 0){
                cou++;
                ans += cou * (cou - 1) / 2;
                cou = 0;
            }
        }
    }

    if(cou != 0){
        cou++;
        ans += cou * (cou - 1) / 2;
    }

    cout << ans << endl;
}