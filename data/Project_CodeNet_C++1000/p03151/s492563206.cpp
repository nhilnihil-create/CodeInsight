#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    ll b[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        sum -= b[i];
    }

    if(sum >= 0){
        ll c[n];
        for(int i = 0; i < n; i++){
            c[i] = a[i] - b[i];
        }

        sort(c, c + n);

        sum = c[n - 1];
        int poj = 0;
        int poj_2 = n - 2;
        ll k = c[poj];
        int ans = 1;
        while(1){
            if(c[poj] >= 0){
                if(poj == 0){
                    ans--;
                }
                break;
            }

            if(c[poj] < 0){
                sum += c[poj];
                ans++;
                while(1){
                    if(sum >= 0){
                        break;
                    }else{
                        sum += c[poj_2];
                        poj_2--;
                        ans++;
                    }
                } 
            }
            poj++;
        }

        cout << ans << endl;

    }else{
        cout << -1 << endl;
    }
}